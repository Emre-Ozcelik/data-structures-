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

#include "graph_am_array.h"

#define SIZE 128
#define MAX_STR_SIZE 2048
#define SEP "---------------------------\n"

void array_print(int array[], int count) {
    printf("{");

    if(count > 0) {
        for(int i = 0; i < (count - 1); i++) {
            printf("%d, ", array[i]);
        }
        printf("%d", array[count - 1]);
    }
    printf("}");
}

void pair_print(pair_struct *pair) {
    printf("{%d, %d}", pair->row, pair->col);
}
/**
 * Simple maximum heap testing.
 */
void test_graph() {
    graph_am_array_struct source;
    int size = 6;

    graph_am_initialize(&source, size);
    graph_am_print(&source);
    printf("\n");

    pair_struct pairs[] = {{1, 2}, {3, 4}, {4, 5}, {3, 5}, {3, 3}, {-1, 9}};
    int count = sizeof pairs / sizeof *pairs;
    graph_am_create(&source, pairs, count);
    graph_am_print(&source);
    printf("\n");

    for(int vertex = 0; vertex < size; vertex++) {
        int connected = graph_am_degree(&source, vertex);
        printf("Vertex %d is connected to %d vertices.\n", vertex, connected);
    }
    printf("\n");

    for(int vertex = 0; vertex < size; vertex++) {
        int count = 0;
        int vertices[size];
        graph_am_neighbours(&source, vertex, vertices, &count);
        printf("Vertex %d neighbours: ", vertex);
        array_print(vertices, count);
        printf("\n");
    }
    printf("\n");

    pair_struct pair0 = {3, 2};
    printf("Add a new edge: ");
    pair_print(&pair0);
    printf("\n");
    bool added = graph_am_add_edge(&source, &pair0);
    printf("Added: %s\n", BOOL_TO_STR(added));
    graph_am_print(&source);

    pair_struct pair1 = {3, 5};
    printf("\nAdd a new edge: ");
    pair_print(&pair1);
    printf("\n");
    added = graph_am_add_edge(&source, &pair1);
    printf("Added: %s\n", BOOL_TO_STR(added));
    graph_am_print(&source);

    int start = 5;
    int vertices[size];
    printf("\nBreadth-first Traversal: %d\n", start);
    graph_am_breadth_traversal(&source, start, vertices, &count);
    array_print(vertices, count);
    printf("\n");
    printf("\nDepth-first Traversal: 5\n");
    graph_am_depth_traversal(&source, start, vertices, &count);
    array_print(vertices, count);
    printf("\n");

    return;
}

/**
 * Test the Adjcency Matrix functions.
 *
 * @param argc - unused
 * @param argv - unused
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    test_graph();
    return (EXIT_SUCCESS);
}
