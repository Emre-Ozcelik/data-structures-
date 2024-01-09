/**
 * -------------------------------------
 * @file  food_utilities.c
 * food_utilities Source Code File
 * -------------------------------------
 * @author Emre Ozcelik, 210807100, ozce7100@mylaurier.ca
 *
 * @version 2023-09-21
 *
 * -------------------------------------
 */
#include "food_utilities.h"
#include <stdio.h>

// Read a food object from the keyboard.
void food_get(food_struct *food) {
    char vegetarian[10];

    printf("Enter the name of the food: ");
    fgets(food->name, NAME_LENGTH, stdin);
    food->name[strcspn(food->name, "\n")] = 0; // remove newline

    printf("Enter the origin (0-%d): ", ORIGINS_SIZE-1);
    scanf("%d", &(food->origin));

    printf("Is it vegetarian? (true/false): ");
    scanf("%s", vegetarian);
    food->is_vegetarian = (strcmp(vegetarian, "true") == 0);

    printf("Enter the number of calories: ");
    scanf("%d", &(food->calories));

    getchar(); // clear newline from buffer
}

// Initialize a food object from delimited string data.
void food_read(food_struct *food, char *line) {
    char vegetarian[10];
    sscanf(line, "%[^,],%d,%[^,],%d", food->name, &(food->origin), vegetarian, &(food->calories));
    food->is_vegetarian = (strcmp(vegetarian, "true") == 0);
}

// Read a file of formatted food string data into an array of food objects.
void foods_read(FILE *fp, food_array *foods) {
    foods->count = 0;
    char line[LINE_LENGTH];
    while (fgets(line, LINE_LENGTH, fp) && foods->count < ARRAY_SIZE) {
        food_read(&foods->items[foods->count], line);
        foods->count++;
    }
}

// Write a food object to a file.
void food_write(FILE *fp, const food_struct *food) {
    fprintf(fp, "%s,%d,%s,%d\n", food->name, food->origin, BOOL_TO_STR(food->is_vegetarian), food->calories);
}

// Write an array of food objects to a file.
void foods_write(FILE *fp, const food_array *foods) {
    for (int i = 0; i < foods->count; i++) {
        food_write(fp, &foods->items[i]);
    }
}

// Copy all vegetarian foods in source to target.
void foods_get_vegetarian(const food_array *const source, food_array *target) {
    target->count = 0;
    for (int i = 0; i < source->count; i++) {
        if (source->items[i].is_vegetarian) {
            food_copy(&target->items[target->count], &source->items[i]);
            target->count++;
        }
    }
}

// Copy all foods of type origin in source to target.
void foods_get_origin(const food_array *const source, food_array *target, int origin) {
    target->count = 0;
    for (int i = 0; i < source->count; i++) {
        if (source->items[i].origin == origin) {
            food_copy(&target->items[target->count], &source->items[i]);
            target->count++;
        }
    }
}
