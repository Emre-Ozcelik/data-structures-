/**
 * -------------------------------------
 * @file  stack_array.h
 * Lab 4 Array-Based Stack Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-09-25
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef STACK_ARRAY_H_
#define STACK_ARRAY_H_

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#include "data.h"

// typedefs

// Structures
/**
 * Initial stack size.
 */
#define STACK_INIT 8

/**
 * Stack header.
 */
typedef struct {
	int capacity;                // current capacity of the stack.
	int top;                     // index of top item of the stack.
	data_type items[STACK_INIT]; // array of data items.
	data_type_string to_string;  // returns string version of data item
	data_type_copy copy;         // copies stack data item
} stack_struct;

// Prototypes

/**
 * Initializes a stack.
 *
 * @param stack - the stack to initialize.
 * @param to_string - the data to_string function
 * @param copy - the data copy function
 */
void stack_initialize(stack_struct *stack, data_type_string to_string,
		data_type_copy copy);

/**
 * Determines if a stack is empty.
 *
 * @param stack - pointer to a stack.
 * @return true if the stack is empty, false otherwise.
 */
bool stack_empty(const stack_struct *stack);

/**
 * Determines if the stack is full.
 * @param stack - pointer to a stack.
 * @return true if the stack is full, false otherwise.
 */
bool stack_full(const stack_struct *stack);

/**
 * Returns the number of items in the stack.
 *
 * @param stack - pointer to a stack.
 * @return the number of items in the stack.
 */
int stack_count(const stack_struct *stack);

/**
 * Pushes an item onto a stack.
 *
 * @param stack - pointer to a stack.
 * @param item - the item to push.
 * @return - true if item pushed, false otherwise (stack is full)
 */
bool stack_push(stack_struct *stack, data_type *item);

/**
 * Returns a copy of the item on the top of a stack. stack is unchanged.
 *
 * @param stack - pointer to a stack.
 * @param item - the item to peek.
 * @return - true if item peeked, false otherwise (stack is empty)
 */
bool stack_peek(const stack_struct *stack, data_type *item);

/**
 * Returns and removes the item on the top of a stack.
 *
 * @param stack - pointer to a stack.
 * @param item - the item to peek.
 * @return - true if item popped, false otherwise (stack is empty)
 */
bool stack_pop(stack_struct *stack, data_type *item);

/**
 * Prints the items in a stack from top to bottom.
 * (For testing only).
 *
 * @param stack - pointer to a stack
 * @param string - string buffer
 * @param size - maximum size of string buffer
 */
void stack_display(const stack_struct *stack, char string[], size_t size);

#endif /* STACK_ARRAY_H_ */
