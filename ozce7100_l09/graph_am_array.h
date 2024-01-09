/**
 * -------------------------------------
 * @file  graph_am_array.h
 * Lab 4 Array-Based graph_am Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-11-10
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef GRAPH_AM_ARRAY_H_
#define GRAPH_AM_ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>

#define BOOL_TO_STR(bool_var) bool_var ? "true" : "false"

// Structures

/**
 * Stores row/col pairs of adjacency matrix items.
 */
typedef struct {
    int row;
    int col;
} pair_struct;

/**
 * Adjacency Matrix Graph header.
 */
typedef struct {
    int size;              // size (width/height) of adjacency matrix
    int *items;            // pointer to 2D array
} graph_am_array_struct;

/**
 * Initializes an adjacency matrix graph.
 *
 * @param source - pointer to a graph
 * @param size - height and width of the graph matrix
 */
void graph_am_initialize(graph_am_array_struct *source, int size);

/**
 * Destroys the contents of an adjacency matrix graph.
 *
 * @param source - pointer to a graph
 */
void graph_am_destroy(graph_am_array_struct *source);

/**
 * Creates a graph from an array of vertex pairs.
 * Pairs containing row < 0 or row >= size are ignored;
 * Pairs containing col < 0 or col >= size are ignored;
 * Pairs containing row == col are a loop and is given a value of 2;
 * All other pairs are given a value of 1 in [row][col] and [col][row].
 * The resulting matrix is symmetrical.
 *
 * @param source - pointer to a graph
 * @param pairs - array of vertex pairs
 * @param count - number of items in pairs
 */
void graph_am_create(graph_am_array_struct *source, pair_struct pairs[], int count);

/**
 * Returns an array of all vertices connected to a vertex.
 * vertices must be defined with a size of source->size.
 *
 * @param source - pointer to a graph
 * @param vertex - index of a vertex
 * @param vertices - array of neighbours
 * @param count - number of vertices
 */
void graph_am_neighbours(const graph_am_array_struct *source, int vertex, int vertices[], int *count);

/**
 * Returns number of vertices connected to vertex.
 *
 * @param source - pointer to a graph
 * @param vertex - index of a vertex
 * @return - number of vertices connected to v
 */
int graph_am_degree(const graph_am_array_struct *source, int vertex);

/**
 * Adds an edge to source. Fails if pair values invalid or edge already in source.
 * Pairs containing row < 0 or row >= size are ignored;
 * Pairs containing col < 0 or col >= size are ignored;
 * Pairs containing row == col are a loop and is given a value of 2;
 * All other pairs are given a value of 1 in [row][col] and [col][row].
 *
 * @param source - pointer to a graph
 * @param pair - pointer to edge to add to source
 * @return - true if the edge was added, false otherwise
 */
bool graph_am_add_edge(graph_am_array_struct *source, pair_struct *pair);

/**
 * Removes an edge from source. Fails if pair values invalid or edge not in source.
 * Pairs containing row < 0 or row >= size are ignored;
 * Pairs containing col < 0 or col >= size are ignored;
 *
 * @param source - pointer to a graph
 * @param pair - pointer to edge to remove from source
 * @return - true if the edge was removed, false otherwise
 */
bool graph_am_remove_edge(graph_am_array_struct *source, pair_struct *pair);

/**
 * Performs a breadth-first traversal of a graph.
 *
 * @param source - pointer to a graph
 * @param vertex - index of a vertex to start traversal from
 * @param vertices - array of vertices
 * @param count - number of vertices
 */
void graph_am_breadth_traversal(const graph_am_array_struct *source, int vertex, int vertices[], int *count);

/**
 * Performs a depth-first traversal of a graph.
 *
 * @param source - pointer to a graph
 * @param vertex - index of a vertex to start traversal from
 * @param vertices - array of vertices
 * @param count - number of vertices
 */
void graph_am_depth_traversal(const graph_am_array_struct *source, int vertex, int vertices[], int *count);

/**
 * Prints the contents of an adjacency matrix graph.
 *
 * @param source - pointer to a graph
 */
void graph_am_print(const graph_am_array_struct *source);

#endif /* GRAPH_AM_ARRAY_H_ */
