/**
 * -------------------------------------
 * @file  list_linked.c
 * Linked List Source Code File
 * -------------------------------------
 * @author ilyas emre ozcleik, 210807100, ozce7100@mylaurier.ca
 *
 * @version 2023-10-20
 *
 * -------------------------------------
 */
#include "list_linked.h"

// Private helper functions

/**
 * Determines if an index is valid.
 *
 * @param list - pointer to a list.
 * @param i - index to check
 * @return - true if i is a valid index, false otherwise
 */
static bool valid_index(const list_linked_struct *source, int i) {
    return ((i >= 0) && (i <= source->count));
}

// Functions

// Initializes a list.
void list_initialize(list_linked_struct **source, data_type_copy copy, data_type_string to_string,
        data_type_compare compare, data_type_destroy destroy) {

    *source = malloc(sizeof(list_linked_struct)); 
    if (*source != NULL) {
        (*source)->front = NULL;
        (*source)->rear = NULL;
        (*source)->count = 0;
        (*source)->copy = copy;
        (*source)->to_string = to_string;
        (*source)->compare = compare;
        (*source)->destroy = destroy;
    }
}

// Destroys a list.
void list_destroy(list_linked_struct **source) {

    if (source != NULL && *source != NULL) {
        list_node *current = (*source)->front;
        while (current != NULL) {
            list_node *next = current->next;
            (*source)->destroy(&(current->item));
            free(current);
            current = next;
        }
        free(*source);
        *source = NULL;
    }
}

// Determines if a list is empty.
bool list_empty(const list_linked_struct *source) {

    return (source == NULL) || (source->front == NULL);

    return true;
}

// Determines if the list is full.
bool list_full(const list_linked_struct *source) {
    return false;
}

// Appends a item to the end of a list.
bool list_append(list_linked_struct *source, data_type *item) {
    if (source == NULL || item == NULL) {
        return false;
    }
    list_node *new_node = malloc(sizeof(list_node));
    if (new_node == NULL) {
        return false;
    }
    new_node->item = malloc(sizeof(data_type));
    if (new_node->item == NULL) {
        free(new_node);
        return false;
    }
    source->copy(new_node->item, item);
    new_node->next = NULL;

    if (source->rear == NULL) {
        source->front = new_node;
    } else {
        source->rear->next = new_node;
    }
    source->rear = new_node;
    source->count++;
    return true;
}

// Prepends a item to the front of a list.
bool list_prepend(list_linked_struct *source, data_type *item) {

    if (source == NULL || item == NULL) {
        return false;
    }
    list_node *new_node = malloc(sizeof(list_node));
    if (new_node == NULL) {
        return false;
    }
    new_node->item = malloc(sizeof(data_type));
    if (new_node->item == NULL) {
        free(new_node);
        return false;
    }
    source->copy(new_node->item, item);

    new_node->next = source->front;
    source->front = new_node;

    if (source->rear == NULL) {
        source->rear = new_node;
    }
    source->count++;
    return true;
}

// Returns the number of items in the list.
int list_count(const list_linked_struct *source) {
    return source->count;
}

// Inserts a item to a list at location i.
bool list_insert(list_linked_struct *source, data_type *item, int i) {
    if (!source || !item || !valid_index(source, i)) {
        return false;
    }
    if (i == 0) {
        return list_prepend(source, item);
    } else if (i == source->count) {
        return list_append(source, item);
    } else {
        list_node *current = source->front;
        for (int pos = 0; pos < i - 1; ++pos) {
            current = current->next;
        }
        list_node *new_node = malloc(sizeof(list_node));
        if (!new_node) {
            return false;
        }
        new_node->item = malloc(sizeof(data_type));
        if (!new_node->item) {
            free(new_node);
            return false;
        }
        source->copy(new_node->item, item);
        new_node->next = current->next;
        current->next = new_node;
        source->count++;
        return true;
    }
}

// Returns a copy of the front of a list.
bool list_peek(const list_linked_struct *source, data_type *item) {

    if (source == NULL || item == NULL || source->front == NULL) {
        return false;
    }
    source->copy(item, source->front->item);
    return true;
}

// Returns a copy of the item matching key in a list.
bool list_key_find(const list_linked_struct *source, const data_type *key, data_type *item) {

    if (source == NULL || key == NULL || item == NULL) {
        return false;
    }
    list_node *current = source->front;
    while (current != NULL) {
        if (source->compare(current->item, key) == 0) {
            source->copy(item, current->item);
            return true;
        }
        current = current->next;
    }
    return false;
}

// Removes and returns the item matching key from the list.
bool list_key_remove(list_linked_struct *source, const data_type *key, data_type *item) {
    if (source == NULL || key == NULL || source->front == NULL) {
        return false;
    }
    list_node *current = source->front;
    list_node *previous = NULL;
    while (current != NULL) {
        if (source->compare(current->item, key) == 0) {
            if (previous == NULL) {  // Removing the first node
                source->front = current->next;
            } else {
                previous->next = current->next;
            }
            if (current->next == NULL) {  // Removing the last node
                source->rear = previous;
            }
            source->copy(item, current->item);
            source->destroy(&(current->item));
            free(current);
            source->count--;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

// Returns the index of key in list. -1 if key not in list.
int list_key_index(const list_linked_struct *source, const data_type *key) {

    int index = 0;
    list_node *current = source->front;
    while (current != NULL) {
        if (source->compare(current->item, key) == 0) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

// Determines if key is in a list.
bool list_key_contains(const list_linked_struct *source, const data_type *key) {

    list_node *current = source->front;
    while (current != NULL) {
        if (source->compare(current->item, key) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Determines number of times key appears in list.
int list_key_count(const list_linked_struct *source, const data_type *key) {
    int count = 0;
    list_node *current = source->front;
    while (current != NULL) {
        if (source->compare(current->item, key) == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Removes and returns the item at index i from a list.
bool list_index_remove(list_linked_struct *source, data_type *item, int i) {

    if (!source || !valid_index(source, i) || source->front == NULL) {
        return false;
    }
    list_node *current = source->front;
    list_node *previous = NULL;
    for (int index = 0; index < i; ++index) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) { // Removing first item
        source->front = current->next;
    } else {
        previous->next = current->next;
    }
    if (current->next == NULL) { // Removing last item
        source->rear = previous;
    }
    source->copy(item, current->item);
    source->destroy(&(current->item));
    free(current);
    source->count--;
    return true;
}

// Finds the maximum item in a list.
bool list_max(const list_linked_struct *source, data_type *item) {
    if (source == NULL || source->front == NULL) {
        return false;
    }
    list_node *current = source->front;
    data_type *max = current->item;
    current = current->next;
    while (current != NULL) {
        if (source->compare(current->item, max) > 0) {
            max = current->item;
        }
        current = current->next;
    }
    source->copy(item, max);
    return true;
}

// Finds the minimum item in a list.
bool list_min(const list_linked_struct *source, data_type *item) {

    if (source == NULL || source->front == NULL) {
        return false;
    }
    list_node *current = source->front;
    data_type *min = current->item;
    current = current->next;
    while (current != NULL) {
        if (source->compare(current->item, min) < 0) {
            min = current->item;
        }
        current = current->next;
    }
    source->copy(item, min);
    return true;
}

// Removes all duplicate items from a list.
void list_clean(list_linked_struct *source) {
    if (source == NULL || source->front == NULL) {
        return;
    }
    list_node *current = source->front;
    while (current != NULL) {
        list_node *runner = current;
        while (runner->next != NULL) {
            if (source->compare(current->item, runner->next->item) == 0) {
                list_node *temp = runner->next;
                runner->next = runner->next->next;
                source->destroy(&(temp->item));
                free(temp);
                source->count--;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// Compares two lists for equality.
bool list_equal(const list_linked_struct *target, const list_linked_struct *source) {

    if (target == NULL || source == NULL) {
        return false; 
    }

    if (target->count != source->count) {
        return false; 
    }

    list_node *target_node = target->front;
    list_node *source_node = source->front;

    while (target_node != NULL && source_node != NULL) {
        if (target->compare(target_node->item, source_node->item) != 0) {
            return false; 
        }
        target_node = target_node->next;
        source_node = source_node->next;
    }

    return true; 
}

// Combines the contents of two source lists into a target list. Items alternate.
void list_combine(list_linked_struct *target, list_linked_struct *source1, list_linked_struct *source2) {

    if (!target || !source1 || !source2) {
        return;
    }
    while (!list_empty(source1) || !list_empty(source2)) {
        data_type temp;
        if (!list_empty(source1)) {
            list_index_remove(source1, &temp, 0);
            list_append(target, &temp);
        }
        if (!list_empty(source2)) {
            list_index_remove(source2, &temp, 0);
            list_append(target, &temp);
        }
    }
}

// Splits a source list alternately into two target lists. Items alternate.
void list_split_alt(list_linked_struct *target1, list_linked_struct *target2, list_linked_struct *source) {

    if (!source || !target1 || !target2) {
        return;
    }
    bool toggle = true;
    while (!list_empty(source)) {
        data_type temp;
        list_index_remove(source, &temp, 0);
        if (toggle) {
            list_append(target1, &temp);
        } else {
            list_append(target2, &temp);
        }
        toggle = !toggle;
    }
}

// Splits a source list into two target lists at the middle of the source list.
void list_split(list_linked_struct *target1, list_linked_struct *target2, list_linked_struct *source) {

    if (!source || !target1 || !target2) {
        return;
    }
    int middle = source->count / 2;
    for (int i = 0; i < middle; i++) {
        data_type temp;
        list_index_remove(source, &temp, 0);
        list_append(target1, &temp);
    }
    while (!list_empty(source)) {
        data_type temp;
        list_index_remove(source, &temp, 0);
        list_append(target2, &temp);
    }
}

// Splits a source list into two target lists based upon a key value.
void list_split_key(list_linked_struct *target1, list_linked_struct *target2, list_linked_struct *source,
        data_type *key) {

     if (!source || !target1 || !target2 || !key) {
        return;
    }
    while (!list_empty(source)) {
        data_type temp;
        list_index_remove(source, &temp, 0);
        if (source->compare(&temp, key) < 0) {
            list_append(target1, &temp);
        } else {
            list_append(target2, &temp);
        }
    }
}

// Prints the items in a list from front to rear.
void list_print(const list_linked_struct *source) {
    char string[DATA_STRING_SIZE];
    list_node *current = source->front;

    while(current != NULL) {
        printf("%s\n", source->to_string(string, DATA_STRING_SIZE, current->item));
        current = current->next;
    }
    return;
}
