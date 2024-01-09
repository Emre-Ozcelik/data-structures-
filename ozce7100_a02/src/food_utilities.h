/**
 * -------------------------------------
 * @file  food_utilities.h
 * food_utilities Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-09-23
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef FOOD_UTILITIES_H_
#define FOOD_UTILITIES_H_

#include "food.h"

// Constants
#define ARRAY_SIZE 40

/**
 * food array structure.
 */
typedef struct {
	int count;
	food_struct items[ARRAY_SIZE];
} food_array;

/**
 * Read a food object from the keyboard.
 *
 * @param food - pointer to food object
 */
void food_get(food_struct *food);

/**
 * Initialize a food object from delimited string data. String is in format:
 * "Lasagna,7,false,135"
 *
 * @param food - pointer to food object
 * @param line - delimited string of food data
 */
void food_read(food_struct *food, char *line);

/**
 * Read a file of formatted food string data into an array of food objects.
 * Strings are in format:
 * "Lasagna,7,false,135"
 *
 * @param fp - pointer to food data file open for reading
 * @param foods - pointer to foods structure
 */
void foods_read(FILE *fp, food_array *foods);

/**
 * Write a food object to a file. Lines are in format:
 * "Lasagna,7,false,135"
 * i.e. equivalent to food_read format
 *
 * @param fp - pointer to food data file open for writing
 * @param food - pointer to food object
 */
void food_write(FILE *fp, const food_struct *food);

/**
 * Write an array of food objects to a file. Lines are in format:
 * "Lasagna,7,false,135"
 * i.e. equivalent to food_read format
 *
 * @param fp - pointer to food data file open for writing
 * @param foods - pointer to foods structure
 */
void foods_write(FILE *fp, const food_array *foods);

/**
 * Copy all vegetarian foods in source to target.
 *
 * @param source - pointer to foods structure
 * @param target - pointer to foods structure
 */
void foods_get_vegetarian(const food_array *const source, food_array *target);

/**
 * Copy all foods of type origin in source to target.
 *
 * @param source - pointer to foods structure
 * @param target - pointer to foods structure
 * @param origin
 */
void foods_get_origin(const food_array *const source, food_array *target,
		int origin);

#endif /* FOOD_UTILITIES_H_ */
