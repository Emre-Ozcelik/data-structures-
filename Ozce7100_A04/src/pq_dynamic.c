/**
 * -------------------------------------
 * @file  list_dynamic.c
 * Dynamic List Source Code File
 * -------------------------------------
 * @author Emre Ozcelik, 210807100, ozce7100@mylaurier.ca
 *
 * @version 2023-10-20
 *
 * -------------------------------------
 */
#include "pq_dynamic.h"

// Functions

#include "pq_dynamic.h"

// Helper function to resize the priority queue
void pq_resize(pq_dynamic_struct *source) {
    int newCapacity = source->capacity * 2;
    data_type *newItems = (data_type *)malloc(newCapacity * sizeof(data_type));

    for (int i = 0; i < source->count; i++) {
        source->copy(&newItems[i], &source->items[i]);
    }

    free(source->items);
    source->items = newItems;
    source->capacity = newCapacity;
}

// Initializes a priority queue.
void pq_initialize(pq_dynamic_struct **source, data_type_copy copy, data_type_string to_string, data_type_compare compare) {
    *source = (pq_dynamic_struct *)malloc(sizeof(pq_dynamic_struct));
    (*source)->capacity = PQ_INIT;
    (*source)->count = 0;
    (*source)->first = -1; // Empty queue
    (*source)->items = (data_type *)malloc(PQ_INIT * sizeof(data_type));
    (*source)->copy = copy;
    (*source)->to_string = to_string;
    (*source)->compare = compare;
}

// Destroys a priority queue.
void pq_destroy(pq_dynamic_struct **source) {
    free((*source)->items);
    free(*source);
    *source = NULL;
}

// Determines if a priority queue is empty.
bool pq_empty(const pq_dynamic_struct *source) {
    return source->count == 0;
}

// Determines if the queue is full.
bool pq_full(const pq_dynamic_struct *source) {

    return false; 
}

// Returns the number of items in the queue.
int pq_count(const pq_dynamic_struct *source) {
    return source->count;
}

// Inserts an item into a priority queue.
bool pq_insert(pq_dynamic_struct *source, data_type *item) {
    if (source->count == source->capacity) {
        pq_resize(source);
    }

    source->copy(&source->items[source->count], item);
    source->count++;

    if (source->first == -1 || source->compare(&source->items[source->count - 1], &source->items[source->first]) > 0) {
        source->first = source->count - 1;
    }

    return true;
}

// Returns a copy of the first of a priority queue.
bool pq_peek(const pq_dynamic_struct *source, data_type *item) {
    if (pq_empty(source)) return false;

    source->copy(item, &source->items[source->first]);
    return true;
}

// Returns and removes the item on the first of a priority queue.
bool pq_remove(pq_dynamic_struct *source, data_type *item) {
    if (pq_empty(source)) return false;

    source->copy(item, &source->items[source->first]);

    for (int i = source->first; i < source->count - 1; i++) {
        source->copy(&source->items[i], &source->items[i + 1]);
    }
    source->count--;

    source->first = -1;
    for (int i = 0; i < source->count; i++) {
        if (source->first == -1 || source->compare(&source->items[i], &source->items[source->first]) > 0) {
            source->first = i;
        }
    }

    return true;
}

// Prints the items in a priority queue from first to rear.
    void pq_print(const pq_dynamic_struct *source) {
        char string[DATA_STRING_SIZE];
        printf("  capacity: %d, count: %d, first: %d, items:\n", source->capacity, source->count, source->first);
        for(int i = 0; i < source->count; i++) {
            printf("%s\n", source->to_string(string, DATA_STRING_SIZE, &(source->items[i])));
        }
        return;
    }
