/**
 * -------------------------------------
 * @file  max_heap_dynamic_struct_dynamic.h
 * Dynamic Maximum Heap Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-10-31
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef MAX_HEAP_DYNAMIC_TXT_
#define MAX_HEAP_DYNAMIC_TXT_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "data.h"

#define HEAP_INIT 7 // Defines three full rows of heap

/**
 * Heap header.
 */
typedef struct {
        int capacity;               // current capacity of the max_heap_dynamic_struct.
        int count;                  // count of number of items in the max_heap_dynamic_struct.
        data_type *items;           // array of data_type items.
        data_type_copy copy;        // copies list data_type item
        data_type_string to_string; // returns string version of data_type item
        data_type_compare compare;  // compares items
} max_heap_dynamic_struct;

// Prototypes

/**
 * Initializes a maximum heap.
 *
 * @param source - pointer to a maximum heap
 * @param copy - data copy function
 * @param to_string - data to string function
 * @param compare - data comparison function
 */
void max_heap_initialize(max_heap_dynamic_struct **source, data_type_copy copy, data_type_string to_string,
        data_type_compare compare);

/**
 * Destroys a maximum heap.
 *
 * @param source - pointer to a maximum heap
 */
void max_heap_destroy(max_heap_dynamic_struct **source);

/**
 * Create a maximum heap from an array of items.
 *
 * @param source - pointer to a maximum heap
 * @param keys - array of items to add to heap
 * @param size - number of items in keys
 */
void max_heap_heapify(max_heap_dynamic_struct *source, data_type keys[], int size);

/**
 * Determines if a maximum heap is empty.
 *
 * @param source - pointer to a maximum heap
 * @return - true if the heap is empty, false otherwise
 */
bool max_heap_empty(const max_heap_dynamic_struct *source);

/**
 * Determines if a maximum heap is full.
 *
 * @param source - pointer to a maximum heap
 * @return - true if the heap is full, false otherwise
 */
bool max_heap_full(const max_heap_dynamic_struct *source);

/**
 * Returns the number of items in a maximum heap.
 *
 * @param source - pointer to a maximum heap
 * @return - number of items in the heap
 */
int max_heap_count(const max_heap_dynamic_struct *source);

/**
 * Inserts an item into a maximum heap.
 * Increases the capacity of the heap if necessary.
 *
 * @param source - pointer to a maximum heap
 * @param item - the item to insert.
 */
bool max_heap_insert(max_heap_dynamic_struct *source, const data_type *item);

/**
 * Returns a copy of the item at the root of a maximum heap, the heap is unchanged.
 *
 * @param source - pointer to a maximum heap
 * @param item - a copy of the root item of the heap
 * @return - true if the heap has a count greater than 0, false otherwise
 */
bool max_heap_peek(const max_heap_dynamic_struct *source, data_type *item);

/**
 * Returns and removes the root item of a maximum heap.
 *
 * @param source - pointer to a maximum heap
 * @param item - the root item of the heap
 * @return - true if the heap has a count greater than 0, false otherwise
 */
bool max_heap_remove(max_heap_dynamic_struct *source, data_type *item);

/**
 * Determines if a maximum heap is valid: i.e. all items are less than or
 * equal to their parents.
 *
 * @param source - pointer to a maximum heap
 * @return - true if heap is valid, false otherwise
 */
bool max_heap_valid(const max_heap_dynamic_struct *source);

/**
 * Remove the largest item from a maximum heap and inserts a new item.
 * The heap count does not change.
 *
 * @param source - pointer to a maximum heap
 * @param replacement - item to insert into the heap
 * @param item - root item removed from the heap
 * @return - true if root replaced, false otherwise (heap is empty)
 */
bool max_heap_replace(max_heap_dynamic_struct *source, data_type *replacement, data_type *item);

/**
 * Prints the items in a maximum heap from root in levelorder.
 *
 * @param source - pointer to a maximum heap.
 */
void max_heap_print(const max_heap_dynamic_struct *source);

#endif /* MAX_HEAP_DYNAMIC_TXT_ */
