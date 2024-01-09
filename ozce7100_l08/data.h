/**
 * -------------------------------------
 * @file  data.h
 * Data Type Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-10-05
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef DATA_H_
#define DATA_H_

#include <stdlib.h>

#define DATA_STRING_SIZE 2048

// Type Definitions
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
 * Returns a string version of a data item.
 *
 * @param string - destination string
 * @param size - maximum size of destination string
 * @param source - pointer to source data
 */
typedef char* (*data_type_string)(char string[], size_t size, const data_type *source);

/**
 * Deep copies data from source to target.
 *
 * @param target - pointer to target data
 * @param source - pointer to source data
 */
typedef void (*data_type_copy)(data_type *target, const data_type *source);

/**
 * Compares two data objects.
 *
 * @param target - pointer to target data
 * @param source - pointer to source data
 * @return
 */
typedef int (*data_type_compare)(const data_type *target, const data_type *source);

/**
 * Frees complete contents of source.
 *
 * @param source - pointer to source data
 */
typedef void (*data_type_destroy)(data_type **source);

// Prototypes
/**
 * Returns string version of data object.
 *
 * @param string - destination string
 * @param size - maximum size of destination string
 * @param source - pointer to source data
 * @return pointer to string
 */
char* data_to_string(char string[], size_t size, const data_type *source);

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
int data_compare(const data_type *target, const data_type *source);

/**
 * Frees complete contents of source.
 *
 * @param source- pointer to source data
 */
void data_destroy(data_type **source);

// Macros
#define BOOL_TO_STR(bool_var) bool_var ? "true" : "false"
#define LESSER(x,y)  data_compare((x), (y)) < 0
#define LESSER_EQUAL(x,y)  data_compare((x), (y)) <= 0
#define GREATER(x,y) data_compare((x), (y)) > 0
#define GREATER_EQUAL(x,y) data_compare((x), (y)) >= 0
#define EQUALS(x,y)  data_compare((x), (y)) == 0
#define NOT(x,y)     data_compare((x), (y)) != 0

#endif /* DATA_H_ */
