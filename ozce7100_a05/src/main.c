/**
 * -------------------------------------
 * @file  main.c
 * Assignment 5 Main Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-10-31
 *
 * -------------------------------------
 * Add other tests as appropriate.
 */
#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "list_linked.h"

#define SIZE 128

/**
 * Simple list testing.
 */
void test_list(void) {
    char buffer[SIZE];
    list_linked_struct *list = NULL;
    data_type item;
    printf("------------\n");
    printf("List testing\n");
    printf("------------\n");

    printf("Initialize list\n");
    list_initialize(&list, data_copy, data_to_string, data_compare, data_destroy);

    printf("list empty: %s\n", BOOL_TO_STR(list_empty(list)));
    printf("list count: %d\n", list_count(list));

    printf("\nAppend data to list:\n");
    data_type items[] = {5, 3, 7, 1, 5, 8, 3};
    int num_items = sizeof(items) / sizeof(data_type);

    for(int i = 0; i < num_items; i++) {
        if(list_append(list, &items[i])) {
            printf("  Appended: %s\n", list->to_string(buffer, SIZE, &items[i]));
        }
    }

    printf("List after appending:\n");
    list_print(list);

    data_type to_insert = 7;
    int index = 3;
    if(list_insert(list, &to_insert, index)) {
        printf("\nInserted %s at index %d.\n", list->to_string(buffer, SIZE, &to_insert), index);
    }

    printf("List after inserting:\n");
    list_print(list);

    data_type to_remove = 5;
    if(list_key_remove(list, &to_remove, &item)) {
        printf("\nRemoved item: %s\n", list->to_string(buffer, SIZE, &item));
    }

    printf("List after removing by key:\n");
    list_print(list);

    data_type to_find = 1;
    if(list_key_find(list, &to_find, &item)) {
        printf("\nFound item: %s\n", list->to_string(buffer, SIZE, &item));
    }

    data_type max_item, min_item;
    if(list_max(list, &max_item)) {
        printf("\nMax item: %s\n", list->to_string(buffer, SIZE, &max_item));
    }
    if(list_min(list, &min_item)) {
        printf("Min item: %s\n", list->to_string(buffer, SIZE, &min_item));
    }

    printf("\nRemoving duplicates from the list.\n");
    list_clean(list);
    printf("List after removing duplicates:\n");
    list_print(list);

    // Destroy the list
    list_destroy(&list);
    printf("list destroyed: %p\n", list);
}

/**
 * Test the list functions.
 *
 * @param argc - unused
 * @param argv - unused
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    test_list();

    return (EXIT_SUCCESS);
}

