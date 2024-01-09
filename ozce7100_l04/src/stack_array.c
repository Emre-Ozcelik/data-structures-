/**
 * -------------------------------------
 * @file  queue_array.c
 * Lab 4 Array-Based queue Source Code File
 * -------------------------------------
 * @author ilyas emre ozcelik, 200807100, email
 *
 * @version 2023-09-25
 *
 * -------------------------------------
 */
#include "queue_array.h"

// Functions

// Initializes a queue.
void queue_initialize(queue_struct *queue, data_type_string to_string,
		data_type_copy copy) {
    queue->capacity = QUEUE_INIT;
    queue->count = 0;
    queue->front = -1;  // front should initially be -1 indicating empty queue
    queue->rear = 0;    // rear should initially be 0 for the next item to be inserted
    queue->to_string = to_string;
    queue->copy = copy;
}

// Determines if a queue is empty.
bool queue_empty(const queue_struct *queue) {
	return queue->count == 0;
}

// Determines if the queue is full.
bool queue_full(const queue_struct *queue) {
	return queue->count == queue->capacity;
}

// Returns the number of items in the queue.
int queue_count(const queue_struct *queue) {
	return queue->count;
}

// Inserts an item into a queue.
bool queue_insert(queue_struct *queue, data_type *item) {
    if (queue_full(queue)) {
        return false;
    }

    queue->copy(&queue->items[queue->rear], item);
    queue->count++;

    if(queue->count == 1) { // If this is the first item being inserted
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;

    return true;
}

// Returns a copy of the front of a queue.
bool queue_peek(const queue_struct *queue, data_type *item) {
	if (!queue_empty(queue)) {
		queue->copy(item, &queue->items[queue->front]);
		return true;
	}
	return false;
}

// Returns and removes the item on the front of a queue.
bool queue_remove(queue_struct *queue, data_type *item) {
    if (queue_empty(queue)) {
        return false;
    }

    queue->copy(item, &queue->items[queue->front]);
    queue->count--;

    if (queue->count == 0) {  // If queue becomes empty after the removal
        queue->front = -1;
        queue->rear = 0;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }

    return true;
}

// Prints the items in a queue from front to bottom.
void queue_display(const queue_struct *queue, char string[], size_t size) {
	// Walk through queue using indexes.
	int i = 0;
	int index = queue->front;

	while (i < queue->count) {
		printf("%s\n", queue->to_string(&(queue->items[index]), string, size));
		index = (index + 1) % queue->capacity;
		i++;
	}
}
