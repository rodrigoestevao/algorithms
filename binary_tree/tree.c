#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

void destroy_tree(struct node *tree) {
    if (tree != NULL) {
        destroy_tree(tree->left);
        destroy_tree(tree->right);
        free(tree);
    }
}

void insert(char data, struct node **leaf) {
    if (*leaf == NULL) {
        *leaf = (struct node *) malloc(sizeof(struct node));
        (*leaf)->data = data;
        (*leaf)->left = NULL;
        (*leaf)->right = NULL;
    } else if (data < (*leaf)->data) {
        insert(data, &(*leaf)->left);
    } else if (data > (*leaf)->data) {
        insert(data, &(*leaf)->right);
    }
}

struct node *search(char data, struct node *tree) {
    struct node *result = NULL;
    if (tree != NULL) {
        if (data == tree->data) {
            result = tree;
        } else if (data < tree->data) {
            result = search(data, tree->left);
        } else if (data > tree->data) {
            result = search(data, tree->right);
        }
    }
    return result;
}

void transversal_preorder(struct node *tree) {
    if (tree != NULL) {
        printf("%c ", tree->data);
        transversal_preorder(tree->left);
        transversal_preorder(tree->right);
    }
}

void transversal_postorder(struct node *tree) {
    if (tree != 0) {
        transversal_postorder(tree->left);
        transversal_postorder(tree->right);
        printf("%c ", tree->data);
    }
}

void transversal_inorder(struct node *tree) {
    if (tree != 0) {
        transversal_inorder(tree->left);
        printf("%c ", tree->data);
        transversal_inorder(tree->right);
    }
}