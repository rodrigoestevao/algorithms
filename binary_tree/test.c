#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

#define NUMBER_OF_LETTERS 26

static char LETTERS[] = {
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
    'S','T','U','V','W','X','Y','Z'
};


struct NODE *create(int elements) {
    struct NODE *node = NULL;
    if ((elements < 1) && (elements > NUMBER_OF_LETTERS)) {
        perror("Invalid number of elements [MIN = 1, MAX = 25]!");
    } else {
        srand(time(NULL));
        int count = 0;
        int index = 0;
        char element = 0;
        printf("\nInput Data: ");
        while (count < elements) {
            index = rand() % NUMBER_OF_LETTERS;
            element = LETTERS[index];
            if (!search(element, node)) {
                printf("%c ", element);
                insert(element, &node);
                ++count;
            }
        }
    }
    return node;
}

int main(int argc, char **argv) {
    int elements = (argc == 2) ? atoi(argv[1]) : 10;
    struct NODE *root = create(elements);
    printf("\nIn-Order  : ");
    transversal_inorder(root);
    printf("\nPost-Order: ");
    transversal_postorder(root);
    printf("\nPre-Order : ");
    transversal_preorder(root);

    int index, medium = (elements / 2) + 1;
    char element = 0;
    while(medium >= 0) {
        index = rand() % NUMBER_OF_LETTERS;
        element = LETTERS[index];
        if (search(element, root)) {
            printf("\nBefore Remove [%c]: ", element);
            transversal_inorder(root);
            delete(element, root);
            printf("\nAfter  Remove [%c]: ", element);
            transversal_inorder(root);
            --medium;
        }
    }
    destroy_tree(root);
}