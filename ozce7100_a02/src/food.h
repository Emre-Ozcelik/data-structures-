/**
 * -------------------------------------
 * @file  functions.h
 * food Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-09-23
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef FOOD_H_
#define FOOD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants
#define NAME_LENGTH 40
#define LINE_LENGTH 120
#define BOOL_TO_STR(bool_var) bool_var ? "true" : "false"

// Externals
extern const char *const ORIGINS[];
extern const int ORIGINS_SIZE;

/**
 * @typedef food_struct
 * food object structure
 * @var char[] name
 * food name, maximum length NAME_LENGTH
 * @var int origin
 * index into the food ORIGINS array
 * @var bool is_vegetarian
 * whether food is vegetarian
 * @var int calories
 * number of calories, >= 0
 */
typedef struct {
	char name[NAME_LENGTH];
	int origin;
	bool is_vegetarian;
	int calories;
} food_struct;

/**
 * Initialize contents of a food object.
 *
 * @param food - pointer to food object
 * @param name - Name of food.
 * @param origin - Origin index.
 * @param is_vegetarian - True if vegetarian, false otherwise.
 * @param calories - number of calories.
 */
void food_initialize(food_struct *food, const char *name, int origin,
		bool is_vegetarian, int calories);

/**
 *
 * @param target - pointer to food object
 * @param source - pointer to food object
 */
void food_copy(food_struct *target, const food_struct *source);

/**
 * Compare two food objects. foods are compared first by name, then by origin.
 *
 * @param source - pointer to food object
 * @param target - pointer to food object
 * @return 0 if foods are the same, < 0 if source < target, > 0 if source > target
 */
int food_compare(const food_struct *source, const food_struct *target);

/**
 * Create a formatted string of a food object as (example):
 * Name:       pizza
 * Origin:     Italian
 * Vegetarian: false
 * Calories:   600
 *
 * @param food - pointer to food object
 * @param string - destination string
 * @param size - maximum size of destination string
 * @return pointer to string
 */
char* food_string(const food_struct *food, char string[], size_t size);

/**
 * Create a formatted string of a food object key data.
 * Consists of the food title and year in the format
 * "title, year" ("pizza, Italian")
 *
 * @param food - pointer to food object
 * @param string - destination string
 * @param size - maximum size of destination string
 * @return pointer to string
 */
char* food_key(const food_struct *food, char *string, int size);

/**
 * Generates a hash value from a food name.
 * The hash is the total of the ASCII values of the
 * characters in the name.
 *
 * @param food - pointer to food object
 * @return integer hash value for food
 */
int food_hash(const food_struct *food);

/**
 * Print numbered origins in the ORIGINS array.
 * Format:
 *
 * Origins
 *  0: Canadian
 *     ...
 * 11: English
 */
void origins_menu(void);

#endif /* FOOD_H_ */
