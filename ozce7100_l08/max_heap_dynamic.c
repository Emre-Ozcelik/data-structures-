/**
 * -------------------------------------
 * @file  max_heap_dynamic_struct_dynamic.c
 * Dynamic Maximum Heap Source Code File
 * -------------------------------------
 * @author emre ozcelik, 210807100, ozce7100@mylaurier.ca
 *
 * @version 2023-10-31
 *
 * -------------------------------------
 */
#include "max_heap_dynamic.h"
/**
 * Swaps items in two data_type pointers.
 *
 * @param a - pointer to an array item
 * @param b - pointer to an array item
 */
static void heap_swap(data_type *a, data_type *b) {
    data_type temp = *a;
    *a = *b;
    *b = temp;
    return;
}

// Moves an item up the heap to its correct position.
static void heapify_up(max_heap_dynamic_struct *source) {
    int index = source->count - 1;
    while (index > 0 && source->compare(&(source->items[index]), &(source->items[(index - 1) / 2])) > 0) {
        heap_swap(&(source->items[index]), &(source->items[(index - 1) / 2]));
        index = (index - 1) / 2;
    }
}

// Moves an item down the heap to its correct position.
static void heapify_down(max_heap_dynamic_struct *source) {
    int index = 0;
    while (index < source->count / 2) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largestChild = leftChild;

        if (rightChild < source->count && source->compare(&(source->items[rightChild]), &(source->items[leftChild])) > 0) {
            largestChild = rightChild;
        }

        if (source->compare(&(source->items[index]), &(source->items[largestChild])) >= 0) {
            break;
        }

        heap_swap(&(source->items[index]), &(source->items[largestChild]));
        index = largestChild;
    }
}

// Initializes a maximum heap.
void max_heap_initialize(max_heap_dynamic_struct **source, data_type_copy copy, data_type_string to_string,
                         data_type_compare compare) {
    *source = malloc(sizeof(max_heap_dynamic_struct));
    assert(*source != NULL);
    (*source)->capacity = HEAP_INIT;
    (*source)->items = malloc(HEAP_INIT * sizeof(data_type));
    assert((*source)->items != NULL);
    (*source)->count = 0;
    (*source)->copy = copy;
    (*source)->to_string = to_string;
    (*source)->compare = compare;
}

// Destroys a maximum heap.
void max_heap_destroy(max_heap_dynamic_struct **source) {
    free((*source)->items);
    (*source)->items = NULL; 
    free(*source);
    *source = NULL;
}

// Create a maximum heap from an array of items.
void max_heap_heapify(max_heap_dynamic_struct *source, data_type keys[], int size) {
    for (int i = 0; i < size; i++) {
        max_heap_insert(source, &keys[i]);
    }
}

// Determines if a maximum heap is empty.
bool max_heap_empty(const max_heap_dynamic_struct *source) {
    return source->count == 0;
}

// Determines if a maximum heap is full.
bool max_heap_full(const max_heap_dynamic_struct *source) {
    return source->count == source->capacity;
}

// Returns the number of items in a maximum heap.
int max_heap_count(const max_heap_dynamic_struct *source) {
    return source->count;
}

// Inserts an item into a maximum heap.
bool max_heap_insert(max_heap_dynamic_struct *source, const data_type *item) {
    if (max_heap_full(source)) {
        int new_capacity = source->capacity * 2;
        data_type *new_items = realloc(source->items, new_capacity * sizeof(data_type));
        if (!new_items) {
            return false;  // Memory allocation failure
        }
        source->items = new_items;
        source->capacity = new_capacity;
    }
    source->copy(&(source->items[source->count]), item);
    source->count++;
    heapify_up(source);
    return true;
}

// Returns a copy of the item at the root of a maximum heap, the heap is unchanged.
bool max_heap_peek(const max_heap_dynamic_struct *source, data_type *item) {
    if (max_heap_empty(source)) {
        return false;
    }
    source->copy(item, &(source->items[0]));
    return true;
}

// Returns and removes the root item of a maximum heap.
bool max_heap_remove(max_heap_dynamic_struct *source, data_type *item) {
    if (max_heap_empty(source)) {
        return false;
    }
    source->copy(item, &(source->items[0]));
    source->copy(&(source->items[0]), &(source->items[source->count - 1]));
    source->count--;
    heapify_down(source);
    return true;
}

// Determines if a maximum heap is valid.
bool max_heap_valid(const max_heap_dynamic_struct *source) {
    for (int i = 0; i < source->count / 2; i++) {
        if (source->compare(&(source->items[i]), &(source->items[2 * i + 1])) < 0 ||
            (2 * i + 2 < source->count && source->compare(&(source->items[i]), &(source->items[2 * i + 2])) < 0)) {
            return false;
        }
    }
    return true;
}

// Remove the largest item from a maximum heap and inserts a new item.
bool max_heap_replace(max_heap_dynamic_struct *source, data_type *replacement, data_type *largest) {
    if (max_heap_empty(source)) {
        return false;
    }
    source->copy(largest, &(source->items[0]));
    source->copy(&(source->items[0]), replacement);
    heapify_down(source);
    return true;
}

// Prints the items in a maximum heap from root in levelorder.
void max_heap_print(const max_heap_dynamic_struct *source) {
    char string[DATA_STRING_SIZE];
    printf("  capacity: %d, count: %d, items:\n", source->capacity, source->count);
    // Walk through source using indexes.
    for(int i = 0; i < source->count; i++) {
        printf("%s\n", source->to_string(string, DATA_STRING_SIZE, &(source->items[i])));
    }
    return;
}
