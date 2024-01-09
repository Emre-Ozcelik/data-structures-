/**
 * -------------------------------------
 * @file  data.h
 * Lab 4 Data Type Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-09-25
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
// Includes
#include <stdio.h>

#include "data.h"

// Functions

// Returns string version of data object.
char* data_to_string(const data_type *data, char string[], size_t size) {
	snprintf(string, size, "%d", *data);
	return string;
}

// Deep copies data from source to target.
void data_copy(data_type *target, const data_type *source) {
	*target = *source;
}

// Compare two data objects.
int data_compare(const data_type *source, const data_type *target) {
	int result = 0;

	if (*source < *target) {
		result = -1;
	} else if (*source > *target) {
		result = 1;
	}
	return (result);
}
