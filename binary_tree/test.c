#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

#define NUMBER_OF_LETTERS 26

struct node *create(int elements) {
    struct node *leaf = NULL;
    if ((elements < 1) && (elements > NUMBER_OF_LETTERS)) {
        perror("Invalid number of elements [MIN = 1, MAX = 25]!");
    } else {
        static char letters[] = {
            'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
            'S','T','U','V','W','X','Y','Z'
        };
        srand(time(NULL));
        int count = 0;
        int index = 0;
        char element = 0;
        printf("\nInput Data: ");
        while (count < elements) {
            index = rand() % NUMBER_OF_LETTERS;
            element = letters[index];
            if (!search(element, leaf)) {
                printf("%c ", element);
                insert(element, &leaf);
                ++count;
            }
        }
    }
    return leaf;
}

int main(int argc, char **argv) {
    int elements = (argc == 2) ? atoi(argv[1]) : 10;
    struct node *root = create(elements);
    printf("\nIn-Order  : ");
    transversal_inorder(root);
    printf("\nPost-Order: ");
    transversal_postorder(root);
    printf("\nPre-Order : ");
    transversal_preorder(root);
    destroy_tree(root);
}