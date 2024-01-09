/**
 * -------------------------------------
 * @file  food.c
 * Assignment 2 food Source Code File
 * -------------------------------------
 * @author emre ozcelik, 210807100, ozce7100@mylaurier.ca
 *
 * @version 2023-09-21
 *
 * -------------------------------------
 */
#include <assert.h>

#include "food.h"

#define NAME_HEADER "Name:"
#define ORIGIN_HEADER "Origin:"
#define VEG_HEADER "Vegetarian:"
#define CALORIES_HEADER "Calories:"
#define HEADER_WIDTH 11

/**
 * Defines an array of strings for possible origins.
 * const keyword means array and contents cannot be changed.
 */
const char *const ORIGINS[] = { "Canadian", "Chinese", "Indian", "Ethiopian",
		"Mexican", "Greek", "Japanese", "Italian", "American", "Scottish",
		"New Zealand", "English" };
// Calculates size of ORIGINS array.
const int ORIGINS_SIZE = sizeof ORIGINS / sizeof *ORIGINS;

void food_initialize(food_struct *food, const char *name, int origin,
		bool is_vegetarian, int calories) {
    assert(food != NULL);
    strncpy(food->name, name, NAME_LENGTH);
    food->origin = origin;
    food->is_vegetarian = is_vegetarian;
    food->calories = calories;
}

void food_copy(food_struct *target, const food_struct *source) {
    assert(target != NULL && source != NULL);
    *target = *source;
}

int food_compare(const food_struct *source, const food_struct *target) {
    int result = strcmp(source->name, target->name);
    if (result == 0) {
        return source->origin - target->origin;
    }
    return result;
}

char* food_string(const food_struct *food, char string[], size_t size) {
    snprintf(string, size, "%-*s %s\n%-*s %s\n%-*s %s\n%-*s %d\n", 
             HEADER_WIDTH, NAME_HEADER, food->name,
             HEADER_WIDTH, ORIGIN_HEADER, ORIGINS[food->origin],
             HEADER_WIDTH, VEG_HEADER, BOOL_TO_STR(food->is_vegetarian),
             HEADER_WIDTH, CALORIES_HEADER, food->calories);
    return string;
}

char* food_key(const food_struct *food, char *string, int size) {
    snprintf(string, size, "%s, %s", food->name, ORIGINS[food->origin]);
    return string;
}

int food_hash(const food_struct *food) {
    int hash_val = 0;
    for (int i = 0; food->name[i]; i++) {
        hash_val += food->name[i];
    }
    return hash_val;
}

void origins_menu(void) {
    for (int i = 0; i < ORIGINS_SIZE; i++) {
        printf("%2d: %s\n", i, ORIGINS[i]);
    }
}
