#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

void destroy_tree(struct NODE *node) {
    if (node != NULL) {
        destroy_tree(node->left);
        destroy_tree(node->right);
        free(node);
    }
}

void insert(char data, struct NODE **node) {
    if (*node == NULL) {
        *node = (struct NODE *) malloc(sizeof(struct NODE));
        (*node)->data = data;
        (*node)->left = NULL;
        (*node)->right = NULL;
    } else if (data < (*node)->data) {
        insert(data, &(*node)->left);
    } else if (data > (*node)->data) {
        insert(data, &(*node)->right);
    }
}

struct NODE *delete(char data, struct NODE *node) {
    struct NODE *result = node;
    if (node != NULL) {
        if (data < result->data) {
            result->left = delete(data, result->left);
        } else if (data > result->data) {
            result->right = delete(data, result->right);
        } else if (data == result->data) {
            if ((result->left == NULL) && (result->right == NULL)) {
                // case 1: no children
                free(result);
                result = NULL;
            } else if (result->left == NULL) {
                // case 2: one child (right)
                struct NODE *temp = result;
                result = result->right;
                free(temp);
            } else if (result->right == NULL) {
                // case 3: one child (left)
                struct NODE *temp = result;
                result = result->left;
                free(temp);
            } else {
                // case 4: two children
                struct NODE *temp = min_value_node(result->right);
                result->data = temp->data;
                result->right = delete(result->data, result->right);
            }
        }
    }
    return result;
}

struct NODE *search(char data, struct NODE *node) {
    struct NODE *result = NULL;
    if (node != NULL) {
        if (data == node->data) {
            result = node;
        } else if (data < node->data) {
            result = search(data, node->left);
        } else if (data > node->data) {
            result = search(data, node->right);
        }
    }
    return result;
}

struct NODE *min_value_node(struct NODE *node) {
    struct NODE *current = node;
    if (current != NULL) {
        while(current->left != NULL) {
            current = current->left;
        }
    }
    return current;
}

struct NODE *max_value_node(struct NODE *node) {
    struct NODE *current = node;
    while(current->right != NULL) {
        current = current->right;
    }
    return current;
}

void transversal_preorder(struct NODE *node) {
    if (node != NULL) {
        printf("%c ", node->data);
        transversal_preorder(node->left);
        transversal_preorder(node->right);
    }
}

void transversal_postorder(struct NODE *node) {
    if (node != 0) {
        transversal_postorder(node->left);
        transversal_postorder(node->right);
        printf("%c ", node->data);
    }
}

void transversal_inorder(struct NODE *node) {
    if (node != 0) {
        transversal_inorder(node->left);
        printf("%c ", node->data);
        transversal_inorder(node->right);
    }
}