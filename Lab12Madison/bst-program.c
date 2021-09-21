#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "bst.h"

void print_key(char *str){
    printf("%s\n", str);
}

int main(void) {
    bst b = bst_new();
    char word[256];
    char op;

    /* while (2 == scanf(" %c %255s", &op, word)) {
        if ('+' == op) {
            b = bst_insert(b, word);
        } else if ('?' == op) {
            printf("%d %s\n", bst_search(b, word), word);
            
        }
      
        }*/

     while (getword(word, sizeof word, stdin) != EOF) {
        printf("inserting %s:\n", word);
        b = bst_insert(b, word);
     }

    printf("bst_inorder:\n");
    bst_inorder(b, print_key);
    printf("bst_preorder:\n");
    bst_preorder(b, print_key);

    printf("deleting 2:\n");
    b = bst_delete(b, "2");
    printf("bst_inorder:\n");
    bst_inorder(b, print_key);
    printf("deleting 1:\n");
    b = bst_delete(b, "1");
    printf("bst_inorder:\n");
    bst_inorder(b, print_key);
    printf("deleting 3:\n");
    b = bst_delete(b, "3");
    printf("bst_inorder:\n");
    bst_inorder(b, print_key);
    printf("bst_preorder:\n");
    bst_preorder(b, print_key);
    
    bst_free(b);

    return EXIT_SUCCESS;
}




    /*int main(void) {
    bst b;
    char word[256];
    b = bst_new();
    while (getword(word, sizeof word, stdin) != EOF) {
        printf("inserting %s:\n", word);
        b = bst_insert(b, word);
    }

    if (bst_search(b, "2") == 1){
        printf("there");
    } else {
        printf("not there");
    }

    if (bst_search(b, "11") == 1){
        printf("there");
    } else {
        printf("not there");
    }
    
    printf("\n");
    printf("bst_inorder:\n");
    bst_inorder(b, print_key);
    printf("\n");
    printf("bst_preorder:\n");
    bst_preorder(b, print_key);
    bst_free(b);
    return EXIT_SUCCESS;
    }*/
