/**
 * -------------------------------------
 * @file  queue_array.h
 * Lab 4 Array-Based queue Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-09-25
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef QUEUE_ARRAY_H_
#define QUEUE_ARRAY_H_

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
 * Initial queue size.
 */
#define QUEUE_INIT 8

/**
 * queue header.
 */
typedef struct {
	int capacity;                // capacity of the queue.
	int count;                   // count of items in queue.
	int front;                   // index of front item of the queue.
	int rear;                    // index of rear item of the queue.
	data_type items[QUEUE_INIT]; // array of data items.
	data_type_string to_string;  // returns string version of data item
	data_type_copy copy;         // copies queue data item
} queue_struct;

// Prototypes

/**
 * Initializes a queue.
 *
 * @param queue - the queue to initialize.
 * @param to_string - the data to_string function
 * @param copy - the data copy function
 */
void queue_initialize(queue_struct *queue, data_type_string to_string,
		data_type_copy copy);

/**
 * Determines if a queue is empty.
 *
 * @param queue - pointer to a queue.
 * @return true if the queue is empty, false otherwise.
 */
bool queue_empty(const queue_struct *queue);

/**
 * Determines if the queue is full.
 * @param queue - pointer to a queue.
 * @return true if the queue is full, false otherwise.
 */
bool queue_full(const queue_struct *queue);

/**
 * Returns the number of items in the queue.
 *
 * @param queue - pointer to a queue.
 * @return the number of items in the queue.
 */
int queue_count(const queue_struct *queue);

/**
 * Inserts an item into a queue.
 *
 * @param queue - pointer to a queue.
 * @param item - the item to insert.
 * @return - true if item inserted, false otherwise (queue is full)
 */
bool queue_insert(queue_struct *queue, data_type *item);

/**
 * Returns a copy of the item on the front of a queue. queue is unchanged.
 *
 * @param queue - pointer to a queue.
 * @param item - the item to peek.
 * @return - true if item peeked, false otherwise (queue is empty)
 */
bool queue_peek(const queue_struct *queue, data_type *item);

/**
 * Returns and removes the item on the front of a queue.
 *
 * @param queue - pointer to a queue.
 * @param item - the item to peek.
 * @return - true if item removeped, false otherwise (queue is empty)
 */
bool queue_remove(queue_struct *queue, data_type *item);

/**
 * Prints the items in a queue from front to rear.
 * (For testing only).
 *
 * @param queue - pointer to a queue
 * @param string - string buffer
 * @param size - maximum size of string buffer
 */
void queue_display(const queue_struct *queue, char string[], size_t size);

#endif /* QUEUE_ARRAY_H_ */
