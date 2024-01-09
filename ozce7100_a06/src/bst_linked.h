/**
 * -------------------------------------
 * @file  bst_linked.h
 * Linked BST Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2023-10-26
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef BST_LINKED_H_
#define BST_LINKED_H_

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#include "data.h"

// typedefs
/**
 * BST node
 */
typedef struct bst_node {
    data_type *item;         // Pointer to the node data_type .
    int height;              // Height of the current node.
    struct bst_node *left;   // Pointer to the left child.
    struct bst_node *right;  // Pointer to the right child.
} bst_node;

/**
 * BST header
 */
typedef struct {
    int count;                  // Number of nodes in the BST.
    bst_node *root;             // Pointer to root node of the BST.
    data_type_copy copy;        // Pointer to data_type  copy function.
    data_type_string to_string; // Pointer to data_type  to string function.
    data_type_destroy destroy;  // Pointer to data_type  destroy function.
    data_type_compare compare;  // Pointer to data comparison function.
} bst_linked_struct;

// Prototypes

/**
 * @param destroy The destroy function for the BST data.
 * @param copy The copy function for the BST data.
 * @param to_string The to string function for the BST data.
 * @param data_compare The comparison function for the BST data.
 * @return A pointer to a new BST.
 */

/**
 * Initializes a BST.
 *
 * @param source - pointer to the BST to initialize.
 * @param copy - the data copy function
 * @param to_string - the data to_string function
 * @param destroy - the data destroy function
 * @param compare - the date compare function
 */
void bst_initialize(bst_linked_struct **source, data_type_copy copy, data_type_string to_string,
        data_type_destroy destroy, data_type_compare compare);

/**
 * Destroys a BST.
 *
 * @param source - pointer to a BST
 */
void bst_destroy(bst_linked_struct **source);

/**
 * Determines if a BST is empty.
 *
 * @param source - pointer to a BST
 * @return true if the BST is empty, false otherwise
 */
bool bst_empty(const bst_linked_struct *source);

/**
 * Determines if a BST is full.
 *
 * @param source - pointer to a BST
 * @return - true if the BST is full, false otherwise
 */
bool bst_full(const bst_linked_struct *source);

/**
 * Returns number of items in a BST.
 *
 * @param source - pointer to a BST
 * @return - number of items in BST
 */
int bst_count(const bst_linked_struct *source);

/**
 * Inserts a copy of an item into a BST.
 *
 * @param source - pointer to a BST Pointer to a BST.
 * @param item - pointer to the item to push
 * @return - true if item inserted, false otherwise
 */
bool bst_insert(bst_linked_struct *source, const data_type *item);

/**
 * Retrieves a copy of a value matching key in a BST.
 *
 * @param source - pointer to a BST
 * @param key - key value to search for
 * @param item - pointer to the item to retrieve
 * @return - true if item retrieved, false otherwise (key not found)
 */
bool bst_retrieve(bst_linked_struct *source, const data_type *key, data_type *item);

/**
 * Removes a value matching key in a BST.
 *
 * @param source - pointer to a BST
 * @param key - key value to search for
 * @param item - pointer to the item to remove
 * @return - true if item removed, false otherwise (key not found)
 */
bool bst_remove(bst_linked_struct *source, const data_type *key, data_type *item);

/**
 * Copies source to target.
 *
 * @param target - pointer to a BST
 * @param source - pointer to a BST
 */
void bst_copy(bst_linked_struct **target, const bst_linked_struct *source);

/**
 * Copies the contents of a BST to an array in inorder.
 *
 * @param source - pointer to a BST
 * @param items - array of items: length must be at least size of BST
 */
void bst_inorder(const bst_linked_struct *source, data_type items[]);

/**
 * Copies the contents of a BST to an array in preorder.
 *
 * @param source - pointer to a BST
 * @param items - array of items: length must be at least size of BST
 */
void bst_preorder(const bst_linked_struct *source, data_type items[]);

/**
 * Copies the contents of a tree to an array in postorder.
 *
 * @param source - pointer to a BST
 * @param items - array of items: length must be at least size of BST
 */
void bst_postorder(const bst_linked_struct *source, data_type items[]);

/**
 * Finds the maximum item in a BST.
 *
 * @param source - pointer to a BST
 * @return - true if a maximum value is found, false otherwise (list is empty)
 */
bool bst_max(const bst_linked_struct *source, data_type *item);

/**
 * Finds the minimum item in a BST.
 *
 * @param source - pointer to a BST
 * @return - true if a minimum value is found, false otherwise (list is empty)
 */
bool bst_min(const bst_linked_struct *source, data_type *item);

/**
 * Finds the number of leaf nodes in a tree.
 *
 * @param source - pointer to a BST
 * @return - count of nodes with no children.
 */
int bst_leaf_count(const bst_linked_struct *source);

/**
 * Finds the number of nodes with one child in a tree.
 *
 * @param source - pointer to a BST
 * @return - count of nodes with one child.
 */
int bst_one_child_count(const bst_linked_struct *source);

/**
 * Finds the number of nodes with two children in a tree.
 *
 * @param source - pointer to a BST
 * @return - count of nodes with two children
 */
int bst_two_child_count(const bst_linked_struct *source);

/**
 * Determines the number of nodes with zero, one, and two children.
 * (May not call bst_leaf_count, bst_one_child_count, or bst_two_child_count.)
 *
 * @param source - pointer to a BST
 * @param zero - count of leaf nodes (no children)
 * @param one - count of nodes with one child
 * @param two - count of nodes with two children
 */
void bst_node_counts(const bst_linked_struct *source, int *zero, int *one, int *two);

/**
 * Determines whether or not a tree is a balanced tree.
 *
 * All node heights are no more than one greater than any child heights.
 * @param source - pointer to a BST
 * @return - true if source is balanced, false otherwise
 */
bool bst_balanced(const bst_linked_struct *source);

/**
 * Determines whether or not a tree is a valid BST.
 *
 * @param source - pointer to a BST
 * @return - true if source is valid, false otherwise
 */
bool bst_valid(const bst_linked_struct *source);

/**
 * Determines if two trees contain same data in same configuration.
 *
 * @param target - pointer to a BST
 * @param source - pointer to a BST
 * @return - true if target is identical to source, false otherwise
 */
bool bst_equals(const bst_linked_struct *target, const bst_linked_struct *source);

/**
 * Prints the items in a BST in preorder.
 *
 * @param source - pointer to a BST
 */
void bst_print(const bst_linked_struct *source);

#endif /* BST_LINKED_H_ */
