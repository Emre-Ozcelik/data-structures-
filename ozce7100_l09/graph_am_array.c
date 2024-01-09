/**
* -------------------------------------
* @file  graph_am_array_struct.c
* Lab 4 Array-Based Stack Source Code File
* -------------------------------------
* @author emre ozcelik, 210807100, ozce7100@mylaurier.ca
*
* @version 2023-11-10
*
* -------------------------------------
*/
#include "graph_am_array.h"


// Initializes an adjacency matrix graph.
void graph_am_initialize(graph_am_array_struct *source, int size) {
   // Must be able to allocate memory to graph data storage.
   source->size = size;
   source->items = calloc(source->size * source->size, sizeof *source->items);
   assert(source->items != NULL);
   return;
}


// Destroys the contents of an adjacency matrix graph.
void graph_am_destroy(graph_am_array_struct *source) {
   free(source->items);  // Free the allocated memory for the items
   source->items = NULL; // Set the pointer to NULL
   source->size = 0;     // Reset the size


}


// Creates a graph from an array of vertex pairs.
void graph_am_create(graph_am_array_struct *source, pair_struct pairs[], int count) {


   for (int i = 0; i < count; i++) {
       int row = pairs[i].row;
       int col = pairs[i].col;


       // Validate indices and add edges
       if (row >= 0 && row < source->size && col >= 0 && col < source->size) {
           if (row == col) {
               *(source->items + row * source->size + col) = 2; // Loop
           } else {
               *(source->items + row * source->size + col) = 1; // Edge
               *(source->items + col * source->size + row) = 1; // Symmetric edge
           }
       }
   }


}


// Returns an array of all vertices connected to a vertex.
void graph_am_neighbours(const graph_am_array_struct *source, int vertex, int vertices[], int *count) {


   *count = 0;
   for (int i = 0; i < source->size; i++) {
       if (*(source->items + vertex * source->size + i) > 0) {
           vertices[*count] = i;
           (*count)++;
       }
   }


}


// Returns number of vertices connected to vertex.
int graph_am_degree(const graph_am_array_struct *source, int vertex) {


   int degree = 0;
   for (int i = 0; i < source->size; i++) {
       if (*(source->items + vertex * source->size + i) > 0) {
           degree++;
       }
   }
   return degree;
}


// Adds an edge to source. Fails if pair values invalid or edge already in source.
bool graph_am_add_edge(graph_am_array_struct *source, pair_struct *pair) {


   int row = pair->row;
   int col = pair->col;


   if (row >= 0 && row < source->size && col >= 0 && col < source->size && *(source->items + row * source->size + col) == 0) {
       *(source->items + row * source->size + col) = (row == col) ? 2 : 1;
       *(source->items + col * source->size + row) = (row == col) ? 2 : 1;
       return true;
   }
   return false;
}


// Removes an edge from source. Fails if pair values invalid or edge not in source.
bool graph_am_remove_edge(graph_am_array_struct *source, pair_struct *pair) {
   int row = pair->row;
   int col = pair->col;


   if (row >= 0 && row < source->size && col >= 0 && col < source->size && *(source->items + row * source->size + col) != 0) {
       *(source->items + row * source->size + col) = 0;
       *(source->items + col * source->size + row) = 0;
       return true;
   }
   return false;
}


// Performs a breadth-first traversal of a graph.
void graph_am_breadth_traversal(const graph_am_array_struct *source, int vertex, int vertices[], int *count) {


   // Initialize a simple array-based queue and visited array
   int queue[source->size];
   bool visited[source->size];
   for (int i = 0; i < source->size; i++) {
       visited[i] = false;
   }


   int front = 0, rear = -1;
   *count = 0;


   // Add the starting vertex to the queue
   queue[++rear] = vertex;
   visited[vertex] = true;


   while (front <= rear) {
       int current_vertex = queue[front++];
       vertices[(*count)++] = current_vertex;


       for (int i = 0; i < source->size; i++) {
           if (*(source->items + current_vertex * source->size + i) > 0 && !visited[i]) {
               queue[++rear] = i;
               visited[i] = true;
           }
       }
   }


}


// Performs a depth-first traversal of a graph.
void graph_am_depth_traversal(const graph_am_array_struct *source, int vertex, int vertices[], int *count) {


   int stack[source->size];
   bool visited[source->size];
   for (int i = 0; i < source->size; i++) {
       visited[i] = false;
   }


   int top = -1;
   *count = 0;


   // Push the starting vertex onto the stack
   stack[++top] = vertex;


   while (top >= 0) {
       int current_vertex = stack[top--];


       if (!visited[current_vertex]) {
           vertices[(*count)++] = current_vertex;
           visited[current_vertex] = true;
       }


       for (int i = source->size - 1; i >= 0; i--) {
           if (*(source->items + current_vertex * source->size + i) > 0 && !visited[i]) {
               stack[++top] = i;
           }
       }
   }
}


// Prints the contents of an adjacency matrix graph.
void graph_am_print(const graph_am_array_struct *source) {
   // Print the column numbers.
   printf("    ");


   for(int i = 0; i < source->size; i++)
       printf("%3d", i);
   printf("\n");
   printf("    ");
   for(int i = 0; i < source->size; i++)
       printf("---");
   printf("\n");


   // Print the row numbers and rows.
   for(int i = 0; i < source->size; i++) {
       printf("%3d|", i);


       for(int j = 0; j < source->size; j++) {
           // find item using offsets
           printf("%3d", *(source->items + i * source->size + j));
       }
       printf("\n");
   }
}




