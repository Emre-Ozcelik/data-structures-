/**
 * -------------------------------------
 * @file  main.c
 * Lab 7 Main Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-10-28
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "bst_linked.h"

#define SIZE 128

/**
 * Simple BST testing.
 */
void test_bst(void) {
    // Define some arbitrary test data
    data_type items[] = {11, 7, 6, 9, 8, 15, 12, 18};
    int count = sizeof items / sizeof *items;
    // Define a BST
    bst_linked_struct *source = NULL;
    bst_initialize(&source, data_copy, data_to_string, data_destroy, data_compare);
    printf("empty: %s\n", BOOL_TO_STR(bst_empty(source)));
    printf("full:  %s\n", BOOL_TO_STR(bst_full(source)));
    printf("count: %d\n", bst_count(source));
    printf("Insert test values:\n");

    for(int i = 0; i < count; i++) {
        bst_insert(source, &items[i]);
    }
    bst_print(source);
    printf("empty: %s\n", BOOL_TO_STR(bst_empty(source)));
    printf("full:  %s\n", BOOL_TO_STR(bst_full(source)));
    printf("count: %d\n", bst_count(source));
    printf("leaf_count: %d\n", bst_leaf_count(source));
    printf("one_child_count: %d\n", bst_one_child_count(source));
    printf("two_child_count: %d\n", bst_two_child_count(source));
    printf("Destroy the BST\n");
    bst_destroy(&source);
}

/**
 * Test the file and string functions.
 *
 * @param argc - unused
 * @param args - unused
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    test_bst();

    return (EXIT_SUCCESS);
}
