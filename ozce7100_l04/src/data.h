/**
 * -------------------------------------
 * @file  data.h
 * Lab 4 Data Type Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-09-25
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef DATA_H_
#define DATA_H_

#include <stdlib.h>

#define BOOL_TO_STR(bool_var) bool_var ? "true" : "false"

// Structures

/**
 * Data structure.
 *
 * Redefine an existing data type. Examples:
 * typedef float data_type;
 * typedef food_struct data_type;
 * typedef movie_struct data_type;
 */
typedef int data_type;

/**
 * Definition of function to print one item of stack data.
 *
 * @param data - pointer to stack data item
 */
typedef char* (*data_type_string)(const data_type *data, char string[],
		size_t size);

typedef void (*data_type_copy)(data_type *target, const data_type *source);

typedef int (*data_type_compare)(const data_type *source,
		const data_type *target);

// Prototypes

/**
 * Returns string version of data object.
 *
 * @param data - pointer to data
 * @param string - destination string
 * @param size - maximum size of destination string
 * @return pointer to string
 */
char* data_to_string(const data_type *data, char string[], size_t size);

/**
 * Deep copies data from source to target.
 *
 * @param target - pointer to copy to.
 * @param source - pointer to copy from.
 */
void data_copy(data_type *target, const data_type *source);

/**
 * Compare two data objects.
 *
 * @param source - pointer to data object
 * @param target - pointer to data object
 * @return 0 if data is the same, < 0 if source < target, > 0 if source > target
 */
int data_compare(const data_type *source, const data_type *target);

// Macros
#define LESSER(x,y)  data_compare((x), (y)) < 0
#define GREATER(x,y) data_compare((x), (y)) > 0
#define EQUALS(x,y)  data_compare((x), (y)) == 0
#define NOT(x,y)     data_compare((x), (y)) != 0

#endif /* DATA_H_ */
