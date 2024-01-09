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
#include "list_dynamic.h"

// Private helper functions

/**
 * Determines if an index is valid.
 *
 * @param list - pointer to a list.
 * @param i - index to check
 * @return - true if i is a valid index, false otherwise
 */
static bool valid_index(const list_dynamic_struct *source, int i) {
    return ((i >= 0) && (i <= source->count));
}

/**
 * Performs a linear search on source->items for key.
 *
 * @param list - pointer to a list.
 * @param key - key of item to look for in list.
 * @return - index of location of key in list, -1 if key not in list.
 */
static int list_linear_search(const list_dynamic_struct *source, const data_type *key) {
    for (int i = 0; i < source->count; i++) {
        if (source->compare(&source->items[i], key) == 0) {
            return i;
        }
    }
    return -1;
}

void list_initialize(list_dynamic_struct **source, data_type_copy copy, data_type_string to_string, data_type_compare compare) {
    *source = malloc(sizeof(list_dynamic_struct));
    if (*source == NULL) {
        return;
    }
    
    (*source)->items = malloc(LIST_INIT * sizeof(data_type));
    if ((*source)->items == NULL) {
        free(*source);
        *source = NULL;
        return;
    }

    (*source)->capacity = LIST_INIT;
    (*source)->count = 0;
    (*source)->copy = copy;
    (*source)->to_string = to_string;
    (*source)->compare = compare;
}


void list_destroy(list_dynamic_struct **source) {
    free((*source)->items);
    free(*source);
    *source = NULL;
}

bool list_empty(const list_dynamic_struct *source) {
    return source->count == 0;
}

bool list_full(const list_dynamic_struct *source) {
    return source->count == source->capacity;
}

bool list_append(list_dynamic_struct *source, data_type *item) {
    if (list_full(source)) {

        return false;
    }
    source->copy(&source->items[source->count], item);
    source->count++;
    return true;
}

int list_count(const list_dynamic_struct *source) {
    return source->count;
}

bool list_insert(list_dynamic_struct *source, data_type *item, int i) {
    if (!valid_index(source, i) || list_full(source)) {
        return false;
    }
    for (int j = source->count; j > i; j--) {
        source->copy(&source->items[j], &source->items[j-1]);
    }
    source->copy(&source->items[i], item);
    source->count++;
    return true;
}

bool list_peek(const list_dynamic_struct *source, data_type *item) {
    if (list_empty(source)) {
        return false;
    }
    source->copy(item, &source->items[0]);
    return true;
}

bool list_key_find(const list_dynamic_struct *source, const data_type *key, data_type *item) {
    int index = list_linear_search(source, key);
    if (index == -1) {
        return false;
    }
    source->copy(item, &source->items[index]);
    return true;
}

bool list_key_remove(list_dynamic_struct *source, const data_type *key, data_type *item) {
    int index = list_linear_search(source, key);
    if (index == -1) {
        return false;
    }
    source->copy(item, &source->items[index]);
    for (int i = index; i < source->count - 1; i++) {
        source->copy(&source->items[i], &source->items[i + 1]);
    }
    source->count--;
    return true;
}

int list_key_index(const list_dynamic_struct *source, const data_type *key) {
    return list_linear_search(source, key);
}

bool list_key_contains(const list_dynamic_struct *source, const data_type *key) {
    return list_linear_search(source, key) != -1;
}

int list_key_count(const list_dynamic_struct *source, const data_type *key) {
    int count = 0;
    for (int i = 0; i < source->count; i++) {
        if (source->compare(&source->items[i], key) == 0) {
            count++;
        }
    }
    return count;
}

bool list_index_remove(list_dynamic_struct *source, data_type *item, int i) {
    if (!valid_index(source, i)) {
        return false;
    }
    source->copy(item, &source->items[i]);
    for (int j = i; j < source->count - 1; j++) {
        source->copy(&source->items[j], &source->items[j + 1]);
    }
    source->count--;
    return true;
}

bool list_max(const list_dynamic_struct *source, data_type *item) {
    if (list_empty(source)) {
        return false;
    }
    data_type max = source->items[0];
    for (int i = 1; i < source->count; i++) {
        if (source->compare(&max, &source->items[i]) < 0) {
            max = source->items[i];
        }
    }
    source->copy(item, &max);
    return true;
}

bool list_min(const list_dynamic_struct *source, data_type *item) {
    if (list_empty(source)) {
        return false;
    }
    data_type min = source->items[0];
    for (int i = 1; i < source->count; i++) {
        if (source->compare(&min, &source->items[i]) > 0) {
            min = source->items[i];
        }
    }
    source->copy(item, &min);
    return true;
}

void list_clean(list_dynamic_struct *source) {
    if (list_empty(source)) {
        return;
    }

    int write_index = 1;
    for (int read_index = 1; read_index < source->count; read_index++) {
        if (source->compare(&source->items[read_index], &source->items[write_index-1]) != 0) {
            source->copy(&source->items[write_index], &source->items[read_index]);
            write_index++;
        }
    }
    source->count = write_index;
}

bool list_equal(const list_dynamic_struct *target, const list_dynamic_struct *source) {
    if (target->count != source->count) {
        return false;
    }
    for (int i = 0; i < target->count; i++) {
        if (source->compare(&target->items[i], &source->items[i]) != 0) {
            return false;
        }
    }
    return true;
}


// Prints the items in a list from front to rear.
void list_print(const list_dynamic_struct *source) {
    char string[DATA_STRING_SIZE];
    printf("  capacity: %d, count: %d, items:\n", source->capacity, source->count);
    for(int i = 0; i < source->count; i++) {
        printf("%s\n", source->to_string(string, DATA_STRING_SIZE, &(source->items[i])));
    }
    return;
}
