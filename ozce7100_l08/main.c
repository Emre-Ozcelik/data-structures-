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
#include "max_heap_dynamic.h"

#define SIZE 128
#define MAX_STR_SIZE 2048
#define SEP "---------------------------\n"

/**
 * Simple maximum heap testing.
 */
void test_heap() {
    max_heap_dynamic_struct *source = NULL;
    max_heap_initialize(&source, data_copy, data_to_string, data_compare);

    printf("Empty Heap:\n");
    max_heap_print(source);
    printf(SEP);
    data_type values[] = {11, 7, 15, 15, 15, 6, 9, 12, 18, 8};
    int n = sizeof values / sizeof *values;

    for(int i = 0; i < n; i++) {
        max_heap_insert(source, &values[i]);
    }
    printf("Heap with data:\n");
    max_heap_print(source);
    printf(SEP);
    printf("Heap valid: %s\n", BOOL_TO_STR(max_heap_valid(source)));
    printf(SEP);

    printf("Remove data:\n");
    data_type item = 0;

    while(max_heap_remove(source, &item)) {
        printf("%d, ", item);
    }
    printf("\n");
    printf(SEP);
    printf("Heapify with data:\n");
    max_heap_heapify(source, values, n);
    max_heap_print(source);
    printf(SEP);

    int key = 13;
    printf("Key: %d\n", key);
    max_heap_replace(source, &key, &item);
    printf("Item replaced: %d\n", item);
    printf(SEP);
    printf("Heap:\n");
    max_heap_print(source);
    printf(SEP);
    printf("Heap valid: %s\n", BOOL_TO_STR(max_heap_valid(source)));
    printf(SEP);
    printf("Remove data:\n");

    while(max_heap_remove(source, &item)) {
        printf("%d, ", item);
    }
    printf("\n");
    printf(SEP);
    max_heap_destroy(&source);
    printf("Heap destroyed: %p\n", source);
    return;
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

    test_heap();
    /*
     int data[] = {1, 3, 7, 2, 9, 5, 8, 1, 4, 6, 2};
     int n = (sizeof data / sizeof *data);
     heap h;
     int i, v;

     printf("-------------\n");
     printf("The Heap\n\n");

     heap_initialize(&h);

     for(i = 0; i < n; i++) {
     heap_insert(&h, data[i]);
     }
     heap_display(&h);

     printf("-------------\n");
     printf("Remove all values from Heap\n\n");

     while(!heap_empty(&h)) {
     v = heap_remove(&h);
     printf("\nData: %d\n", v);
     printf("Remaining:\n");
     heap_display(&h);
     }

     printf("\n-------------\n");
     printf("Sorting contents of array\n\n");
     heap_sort(data, n);

     for(i = 0; i < n; i++) {
     printf("%d  ", data[i]);
     }
     printf("\n");
     return (0);
     */
    return (EXIT_SUCCESS);
}
