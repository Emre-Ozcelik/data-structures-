/**
 * -------------------------------------
 * @file  bst_linked.c
 * Linked BST Source Code File
 * -------------------------------------
 * @author emre ozcelik, 210807100, ozce7100@mylaurier.ca
 *
 * @version 2023-10-26
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst_linked.h"

// Macro for comparing node heights
#define MAX_HEIGHT(a,b) ((a) > (b) ? a : b)
// Macros for data_type comparison
#define LESS_THAN_EQUAL(x,y) compare((x), (y)) <= 0
#define GREATER_THAN_EQUAL(x,y) compare((x), (y)) >= 0

//--------------------------------------------------------------------
// Local Functions

/**
 * Initializes a new BST node with a copy of item.
 *
 * @param source pointer to a BST source
 * @param item pointer to the item to assign to the node
 * @return a pointer to a new BST node
 */
static bst_node* bst_node_initialize(data_type_copy copy, const data_type *item) {
    // Base case: create a new node containing a copy of item.
    bst_node *node = malloc(sizeof *node);
    node->item = malloc(sizeof *node->item);
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    copy(node->item, item);
    return node;
}

/**
 * Helper function to determine the height of node - handles empty node.
 * @param node The node to process.
 * @return The height of the current node.
 */
static int bst_node_height(const bst_node *node) {
    int height = 0;

    if(node != NULL) {
        height = node->height;
    }
    return height;
}

/**
 * Updates the height of a node. Its height is the max of the heights of its
 * child nodes, plus 1.
 * @param node The node to process.
 */
static void bst_update_height(bst_node *node) {
    int left_height = bst_node_height(node->left);
    int right_height = bst_node_height(node->right);

    node->height = MAX_HEIGHT(left_height, right_height) + 1;
    return;
}

/**
 * Destroys a node and its children.
 * @param source Pointer to a BST.
 * @param node Pointer to the node to destroy.
 */
static void bst_destroy_aux(bst_linked_struct *source, bst_node **node) {

    if (*node != NULL) {
        bst_destroy_aux(source, &(*node)->left);
        bst_destroy_aux(source, &(*node)->right);
        source->destroy(&(*node)->item); // Free the data item
        free(*node); // Free the node itself
        *node = NULL;
    }

}

/**
 * Inserts item into a BST. Insertion must preserve the BST definition.
 * item may appear only once in source.
 *
 * @param source - pointer to a BST
 * @param node - pointer to a node
 * @param item - the item to insert
 * @return - true if item inserted, false otherwise
 */
static bool bst_insert_aux(bst_linked_struct *source, bst_node **node, const data_type *item) {
    bool inserted = false;

    if(*node == NULL) {
        // Base case: add a new node containing the item.
        *node = bst_node_initialize(source->copy, item);
        source->count += 1;
        inserted = true;
    } else {
        // Compare the node data_type against the new item.
        int comp = source->compare(item, (*node)->item);

        if(comp < 0) {
            // General case: check the left subsource.
            inserted = bst_insert_aux(source, &(*node)->left, item);
        } else if(comp > 0) {
            // General case: check the right subsource.
            inserted = bst_insert_aux(source, &(*node)->right, item);
        }
    }
    if(inserted) {
        // Update the node height if any of its children have been changed.
        bst_update_height(*node);
    }
    return inserted;
}

//--------------------------------------------------------------------
// Functions

// Initializes a BST.
void bst_initialize(bst_linked_struct **source, data_type_copy copy, data_type_string to_string,
        data_type_destroy destroy, data_type_compare compare) {
    *source = malloc(sizeof **source);
    assert(source != NULL);
    (*source)->root = NULL;
    (*source)->count = 0;
    (*source)->copy = copy;
    (*source)->to_string = to_string;
    (*source)->destroy = destroy;
    (*source)->compare = compare;
    return;
}

// Destroys a BST.
void bst_destroy(bst_linked_struct **source) {
    if (*source != NULL) {
        bst_destroy_aux(*source, &(*source)->root);
        free(*source);
        *source = NULL;
    }
}

// Determines if a BST is empty.
bool bst_empty(const bst_linked_struct *source) {
    return source->root == NULL;
}

// Determines if a BST is full.
bool bst_full(const bst_linked_struct *source) {
    return false;
}

// Returns number of items in a BST.
int bst_count(const bst_linked_struct *source) {
    return source->count;
}

static void bst_inorder_aux(bst_node *node, data_type items[], int *index) {
    if (node != NULL) {
        bst_inorder_aux(node->left, items, index);
        items[(*index)++] = *(node->item);
        bst_inorder_aux(node->right, items, index);
    }
}

void bst_inorder(const bst_linked_struct *source, data_type items[]) {
    int index = 0;
    bst_inorder_aux(source->root, items, &index);
}

static void bst_preorder_aux(bst_node *node, data_type items[], int *index) {
    if (node != NULL) {
        items[(*index)++] = *(node->item);
        bst_preorder_aux(node->left, items, index);
        bst_preorder_aux(node->right, items, index);
    }
}

void bst_preorder(const bst_linked_struct *source, data_type items[]) {
    int index = 0;
    bst_preorder_aux(source->root, items, &index);
}

// Copies the contents of a BST to an array in postorder.
static void bst_postorder_aux(bst_node *node, data_type items[], int *index) {
    if (node != NULL) {
        bst_postorder_aux(node->left, items, index);
        bst_postorder_aux(node->right, items, index);
        items[(*index)++] = *(node->item);
    }
}

void bst_postorder(const bst_linked_struct *source, data_type items[]) {
    int index = 0;
    bst_postorder_aux(source->root, items, &index);
}
// Inserts a copy of an item into a BST.
bool bst_insert(bst_linked_struct *source, const data_type *item) {
    return bst_insert_aux(source, &(source->root), item);
}

bool bst_retrieve(bst_linked_struct *source, const data_type *key, data_type *item) {
    bst_node *current = source->root;
    while (current != NULL) {
        int comp = source->compare(key, current->item);
        if (comp == 0) {
            *item = *(current->item);
            return true;
        } else if (comp < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

bool bst_remove_node(bst_node **node, const data_type *key, data_type *item) {
    if (*node == NULL) {
        return false;
    }

    if (*key < (*node)->item) {
        return bst_remove_node(&((*node)->left), key, item);
    } else if (*key > (*node)->item) {
        return bst_remove_node(&((*node)->right), key, item);
    } else {
        *item = (*node)->item;

        if ((*node)->left == NULL && (*node)->right == NULL) {
            free(*node);
            *node = NULL;
        } else if ((*node)->left == NULL) {
            bst_node *temp = *node;
            *node = (*node)->right;
            free(temp);
        } else if ((*node)->right == NULL) {
            bst_node *temp = *node;
            *node = (*node)->left;
            free(temp);
        } else {
            bst_node *temp = (*node)->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            (*node)->item = temp->item;
            bst_remove_node(&((*node)->right), &(temp->item), item);
        }
        return true;
    }
}

bool bst_remove(bst_linked_struct *source, const data_type *key, data_type *item) {
    if (source == NULL || source->root == NULL) {
        return false;
    }
    return bst_remove_node(&(source->root), key, item);
}


static bst_node* bst_copy_aux(bst_node* node, data_type_copy copy) {
    if (node == NULL) return NULL;
    bst_node* new_node = bst_node_initialize(copy, node->item);
    new_node->left = bst_copy_aux(node->left, copy);
    new_node->right = bst_copy_aux(node->right, copy);
    return new_node;
}

void bst_copy(bst_linked_struct **target, const bst_linked_struct *source) {
    if (source == NULL || target == NULL) return;
    *target = malloc(sizeof(bst_linked_struct));
    (*target)->root = bst_copy_aux(source->root, source->copy);

}

bool bst_max(const bst_linked_struct *source, data_type *item) {
    if (source == NULL || source->root == NULL) return false;
    bst_node *current = source->root;
    while (current->right != NULL) current = current->right;
    *item = *(current->item);
    return true;
}

bool bst_min(const bst_linked_struct *source, data_type *item) {
    if (source == NULL || source->root == NULL) return false;
    bst_node *current = source->root;
    while (current->left != NULL) current = current->left;
    *item = *(current->item);
    return true;
}

int bst_leaf_count_helper(const bst_node *node) {
    if (node == NULL) {
        return 0;
    } else if (node->left == NULL && node->right == NULL) {

        return 1;
    } else {

        return bst_leaf_count_helper(node->left) + bst_leaf_count_helper(node->right);
    }
}

int bst_leaf_count(const bst_linked_struct *source) {
    if (source == NULL || source->root == NULL) {

        return 0;
    }
    return bst_leaf_count_helper(source->root);
}

int bst_one_child_count_helper(const bst_node *node) {
    if (node == NULL) {

        return 0;
    } else if ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL)) {

        return 1 + bst_one_child_count_helper(node->left) + bst_one_child_count_helper(node->right);
    } else {

        return bst_one_child_count_helper(node->left) + bst_one_child_count_helper(node->right);
    }
}

int bst_one_child_count(const bst_linked_struct *source) {
    if (source == NULL || source->root == NULL) {
        return 0;
    }
    return bst_one_child_count_helper(source->root);
}

int bst_two_child_count_helper(const bst_node *node) {
    if (node == NULL) {
        return 0;
    } else if (node->left != NULL && node->right != NULL) {
        return 1 + bst_two_child_count_helper(node->left) + bst_two_child_count_helper(node->right);
    } else {

        return bst_two_child_count_helper(node->left) + bst_two_child_count_helper(node->right);
    }
}

int bst_two_child_count(const bst_linked_struct *source) {
    if (source == NULL || source->root == NULL) {
        return 0;
    }
    return bst_two_child_count_helper(source->root);
}

void bst_node_counts_helper(const bst_node *node, int *zero, int *one, int *two) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {

        (*zero)++;
    } else if (node->left == NULL || node->right == NULL) {
        (*one)++;
    } else {

        (*two)++;
    }

    bst_node_counts_helper(node->left, zero, one, two);
    bst_node_counts_helper(node->right, zero, one, two);
}

void bst_node_counts(const bst_linked_struct *source, int *zero, int *one, int *two) {
    if (source == NULL || source->root == NULL) {

        *zero = 0;
        *one = 0;
        *two = 0;
        return;
    }


    *zero = 0;
    *one = 0;
    *two = 0;

    bst_node_counts_helper(source->root, zero, one, two);
}


int bst_height(const bst_node *node) {
    if (node == NULL) {

        return -1;
    }
    int left_height = bst_height(node->left);
    int right_height = bst_height(node->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

bool bst_is_balanced(const bst_node *node) {
    if (node == NULL) {
        return true;
    }

    int left_height = bst_height(node->left);
    int right_height = bst_height(node->right);

    if (abs(left_height - right_height) <= 1 
        && bst_is_balanced(node->left) 
        && bst_is_balanced(node->right)) {
        return true;
    }
    return false;
}

bool bst_balanced(const bst_linked_struct *source) {
    if (source == NULL || source->root == NULL) {
        return true;
    }
    return bst_is_balanced(source->root);
}


bool is_bst_valid(const bst_node *node, data_type min, data_type max) {
    if (node == NULL) {
        return true;
    }

    if (node->item <= min || node->item >= max) {
        return false;
    }

    return is_bst_valid(node->left, min, node->item) && is_bst_valid(node->right, node->item, max);
}

bool bst_valid(const bst_linked_struct *source) {
    if (source == NULL || source->root == NULL) {
        return true;
    }
    return is_bst_valid(source->root, INT_MIN, INT_MAX);
}

bool bst_nodes_equal(const bst_node *node1, const bst_node *node2) {
    if (node1 == NULL && node2 == NULL) {
        return true;
    }
    if (node1 != NULL && node2 != NULL) {
        return (node1->item == node2->item) && 
               bst_nodes_equal(node1->left, node2->left) && 
               bst_nodes_equal(node1->right, node2->right);
    }
    return false;
}

bool bst_equals(const bst_linked_struct *target, const bst_linked_struct *source) {
    if (target == NULL && source == NULL) {
        return true;
    }
    if (target != NULL && source != NULL) {
        return bst_nodes_equal(target->root, source->root);
    }
    return false;
}

/**
 * Private helper function to print contents of BS in preorder.
 *
 * @param to_string - function to print data_type
 * @param node - pointer to bst_node
 */
static void bst_print_aux(data_type_string to_string, bst_node *node) {
    char string[DATA_STRING_SIZE];

    if(node != NULL) {
        printf("%s\n", to_string(string, DATA_STRING_SIZE, node->item));
        bst_print_aux(to_string, node->left);
        bst_print_aux(to_string, node->right);
    }
    return;
}

// Prints the items in a BST in preorder.
void bst_print(const bst_linked_struct *source) {
    printf("  count: %d, height: %d, items:\n", source->count, source->root->height);
    bst_print_aux(source->to_string, source->root);
    printf("\n");
    return;
}
