#ifndef _TREE_
#define _TREE_

struct NODE {
    char data;
    struct NODE *left;
    struct NODE *right;
};

void destroy_tree(struct NODE *node);
void insert(char data, struct NODE **node);
struct NODE *delete(char data, struct NODE *node);
struct NODE *search(char data, struct NODE *node);
struct NODE *min_value_node(struct NODE *node);
void preorder(struct NODE *node);
void postorder(struct NODE *node);
void inorder(struct NODE *node);

#endif

