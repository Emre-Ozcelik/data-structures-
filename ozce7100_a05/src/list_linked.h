/**
 * -------------------------------------
 * @file  list_linked.h
 * Linked List Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-10-31
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef LIST_LINKED_H_
#define LIST_LINKED_H_

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
 * List node.
 */
typedef struct list_node {
    data_type *item;          // Pointer to the node data_type .
    struct list_node *next; // Pointer to the next list node.
} list_node;

/**
 * list header.
 */
typedef struct {
    list_node *front;          // Pointer to the front node of the list.
    list_node *rear;           // Pointer to the rear node of the list.
    int count;                  // count of items in list.
    data_type_copy copy;        // copies list data item
    data_type_string to_string; // returns string version of data item
    data_type_compare compare;  // compares items
    data_type_destroy destroy;  // Pointer to data_type destroy function.
} list_linked_struct;

// Prototypes

/**
 * Initializes a list.
 *
 * @param source - the list to initialize
 * @param copy - the data copy function
 * @param to_string - the data to_string function
 * @param compare - the data compare function
 * @param destroy - the data destroy function
 */
void list_initialize(list_linked_struct **source, data_type_copy copy, data_type_string to_string,
        data_type_compare compare, data_type_destroy destroy);

/**
 * Destroys a list.
 *
 * @param source - pointer to a list
 */
void list_destroy(list_linked_struct **source);

/**
 * Determines if a list is empty.
 *
 * @param source - pointer to a list
 * @return true if the list is empty, false otherwise
 */
bool list_empty(const list_linked_struct *source);

/**
 * Determines if the list is full
 * @param source - pointer to a list
 * @return true if the list is full, false otherwise
 */
bool list_full(const list_linked_struct *source);

/**
 * Appends a item to the rear of a list.
 *
 * @param source - pointer to a list
 * @param item - the item to append
 * @return - true if item appended, false otherwise (list is full)
 */
bool list_append(list_linked_struct *source, data_type *item);

/**
 * Prepends a item to the front of a list.
 *
 * @param source - pointer to a list
 * @param item - the item to prepend
 * @return - true if item prepended, false otherwise (list is full)
 */
bool list_prepend(list_linked_struct *source, data_type *item);

/**
 * Returns the number of items in the list.
 *
 * @param source - pointer to a list
 * @return the number of items in the list
 */
int list_count(const list_linked_struct *source);

/**
 * Inserts a item to a list at location i.
 * If i is less than 0 the new item is prepended to the list.
 * If i is greater than the length of source the new item is appended to the list.
 *
 * @param source - pointer to a list
 * @param item - the item to insert
 * @param i - the index to put the new item
 * @return - true if item inserted, false otherwise (list is full)
 */
bool list_insert(list_linked_struct *source, data_type *item, int i);
/**
 * Returns a copy of the item on the front of a list. list is unchanged.
 *
 * @param source - pointer to a list
 * @param item - the item to peek
 * @return - true if item peeked, false otherwise (list is empty)
 */
bool list_peek(const list_linked_struct *source, data_type *item);

/**
 * Removes and returns the item at index i from a list. All items to the right
 * of list[i] must be moved to the previous index.
 *
 * @param source - pointer to a list
 * @param item - a copy of the item removed
 * @param i - index of item to remove
 * @return - true if item is removed, false otherwise
 */
bool list_index_remove(list_linked_struct *source, data_type *item, int i);

/**
 * Returns a copy of the item matching key in a list.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @param item - a copy of the item found
 * @return - true if key is found, false otherwise
 */
bool list_key_find(const list_linked_struct *source, const data_type *key, data_type *item);

/**
 * Removes and returns the item matching key from the list. All items to the right
 * of list[i] must be moved to the previous index.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @param item - a copy of the item found
 * @return - true if key is found, false otherwise
 */
bool list_key_remove(list_linked_struct *source, const data_type *key, data_type *item);

/**
 * Returns the index of key in list. -1 if key not in list.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @return - index of the location of key in list
 */
int list_key_index(const list_linked_struct *source, const data_type *key);

/**
 * Determines if key is in a list.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @return - true if key in list, false otherwise
 */
bool list_key_contains(const list_linked_struct *source, const data_type *key);

/**
 * Determines number of times key appears in a list.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @return - number of times key appears in list
 */
int list_key_count(const list_linked_struct *source, const data_type *key);

/**
 * Finds the maximum item in a list.
 *
 * @param source - pointer to a list
 * @param item - pointer to the maximum item
 * @return - true if a maximum value is found, false otherwise (list is empty)
 */
bool list_max(const list_linked_struct *source, data_type *item);

/**
 * Finds the minimum item in a list.
 *
 * @param source - pointer to a list
 * @param item - pointer to the minimum item
 * @return - true if a minimum value is found, false otherwise (list is empty)
 */
bool list_min(const list_linked_struct *source, data_type *item);

/**
 * Removes all duplicate items from a list. Only the first copy of each item remains
 * in the list.
 *
 * @param source - pointer to a list
 */
void list_clean(list_linked_struct *source);

/**
 * Compares two lists for equality. Lists are equal if they contain the equivalent items
 * in the same order.
 *
 * @param source - the first list to compare
 * @param target - the second list to compare
 * @return - true if lists are identical, false otherwise
 */
bool list_equal(const list_linked_struct *target, const list_linked_struct *source);

/**
 * Combines the contents of two source lists into a target list. Items alternate.
 * Source lists are empty (not destroyed) when the function completes.
 * Moves nodes, not data.
 *
 * @param target - pointer to target list
 * @param source1 - pointer to first source list
 * @param source2 - pointer to second source list
 */
void list_combine(list_linked_struct *target, list_linked_struct *source1, list_linked_struct *source2);

/**
 * Splits a source list alternately into two target lists. Items alternate.
 * Source list is empty (not destroyed) when function completes.
 * Moves nodes, not data.
 *
 * @param target1 - pointer to first target list
 * @param target2 - pointer to second target list
 * @param source - pointer to source list
 */
void list_split_alt(list_linked_struct *target1, list_linked_struct *target2, list_linked_struct *source);

/**
 * Splits a source list into two target lists at the middle of the source list.
 * If the source list is even in size, it is split evenly.
 * If the source list is odd in size, target1 gets the large half of source.
 * Source list is empty (not destroyed) when function completes.
 * Moves nodes, not data.
 *
 * @param target1 - pointer to first target list
 * @param target2 - pointer to second target list
 * @param source - pointer to source list
 */
void list_split(list_linked_struct *target1, list_linked_struct *target2, list_linked_struct *source);

/**
 * Splits a source list into two target lists based upon a key value.
 * target1 contains all values < key, target2 contains all values >= key.
 * Source list is empty (not destroyed) when function completes.
 * Moves nodes, not data.
 *
 * @param target1 - pointer to first target list
 * @param target2 - pointer to second target list
 * @param source - pointer to source list
 * @param key - item to split list with
 */
void list_split_key(list_linked_struct *target1, list_linked_struct *target2, list_linked_struct *source,
        data_type *key);

/**
 * Prints the items in a list from front to rear.
 *
 * @param source - pointer to a list.
 */
void list_print(const list_linked_struct *source);

#endif /* LIST_LINKED_H_ */
