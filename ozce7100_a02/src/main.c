/**
 * -------------------------------------
 * @file  main.c
 * Assignment 2 Main Source Code File
 * -------------------------------------
 * @author Ilyas Emre Ozcelik, 210807100, ozce7100@mylaurier.ca
 *
 * @version 2023-09-21
 *
 * -------------------------------------
 */
#include <stdlib.h>
#include <stdio.h>

#include "food_utilities.h"


int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);
	char string[LINE_LENGTH] = "";
	food_array foods;
	food_array veg;
	food_array italian;

	printf("----------------\n");
	printf("Define one food:\n");
	food_struct food = { "Greek salad", 5, true, 185 };
	printf("%s", food_string(&food, string, LINE_LENGTH));
	printf("key: %s\n", food_key(&food, string, LINE_LENGTH));
	printf("hash: %d\n", food_hash(&food));
	fflush(stdout);

	printf("----------------\n");
	printf("Get one food from keyboard:\n");
	food_get(&food);
	printf("\n%s\n", food_string(&food, string, LINE_LENGTH));
	fflush(stdout);

	printf("----------------\n");
	printf("Read foods from string:\n");
	char *line = "Lasagna,7,false,135\n";
	food_read(&food, line);
	printf("\n%s\n", food_string(&food, string, LINE_LENGTH));
	fflush(stdout);

	printf("----------------\n");
	printf("Read foods from file:\n");
	FILE *fp = fopen("foods.txt", "r");
	foods_read(fp, &foods);
	fclose(fp);

	for (int i = 0; i < foods.count; i++) {
		printf("%s\n", food_string(&(foods.items[i]), string, LINE_LENGTH));
	}
	fflush(stdout);

	printf("\n------------------\nVegetarian:\n");
	foods_get_vegetarian(&foods, &veg);

	for (int i = 0; i < veg.count; i++) {
		printf("%s\n", food_string(&(veg.items[i]), string, LINE_LENGTH));
	}
	fp = fopen("veggies.txt", "w");
	foods_write(fp, &veg);
	fclose(fp);

	printf("\n------------------\nItalian:\n");
	foods_get_origin(&foods, &italian, 7);

	for (int i = 0; i < italian.count; i++) {
		printf("%s\n", food_string(&(italian.items[i]), string, LINE_LENGTH));
	}
	fp = fopen("italian.txt", "w");
	foods_write(fp, &italian);
	fclose(fp);

	return 0;
}
