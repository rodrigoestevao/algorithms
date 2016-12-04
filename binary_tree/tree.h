#ifndef _TREE_
#define _TREE_

struct node {
    char data;
    struct node *left;
    struct node *right;
};

void destroy_tree(struct node *leaf);
void insert(char data, struct node **leaf);
struct node *search(char data, struct node *leaf);
void transversal_preorder(struct node *tree);
void transversal_postorder(struct node *tree);
void transversal_inorder(struct node *tree);

#endif

