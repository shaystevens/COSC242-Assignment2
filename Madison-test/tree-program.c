#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "tree.h"

static void print_info(int freq, char *word) {
    printf("%-4d %s\n", freq, word);
}

int main(void) {
    tree t = tree_new(BST);
    char word[256];
    char op;

    /* while (2 == scanf(" %c %255s", &op, word)) {
        if ('+' == op) {
            b = rbt_insert(b, word);
        } else if ('?' == op) {
            printf("%d %s\n", rbt_search(b, word), word);
            
        }
      
        }*/

     while (getword(word, sizeof word, stdin) != EOF) {
        printf("inserting %s:\n", word);
        t = tree_insert(t, word);
     }

     /*printf("rbt_inorder:\n");
       rbt_inorder(b, print_key);*/
    printf("tree_preorder:\n");
    tree_preorder(t, print_info);

    printf("tree depth\n");
    printf("%d", tree_depth(t));

    /* printf("deleting 2:\n");
    b = rbt_delete(b, "2");
    printf("rbt_inorder:\n");
    rbt_inorder(b, print_key);
    printf("deleting 1:\n");
    b = rbt_delete(b, "1");
    printf("rbt_inorder:\n");
    rbt_inorder(b, print_key);
    printf("deleting 3:\n");
    b = rbt_delete(b, "3");
    printf("rbt_inorder:\n");
    rbt_inorder(b, print_key);
    printf("rbt_preorder:\n");
    rbt_preorder(b, print_key);*/
    
    tree_free(t);

    return EXIT_SUCCESS;
}




    /*int main(void) {
    rbt b;
    char word[256];
    b = rbt_new();
    while (getword(word, sizeof word, stdin) != EOF) {
        printf("inserting %s:\n", word);
        b = rbt_insert(b, word);
    }

    if (rbt_search(b, "2") == 1){
        printf("there");
    } else {
        printf("not there");
    }

    if (rbt_search(b, "11") == 1){
        printf("there");
    } else {
        printf("not there");
    }
    
    printf("\n");
    printf("rbt_inorder:\n");
    rbt_inorder(b, print_key);
    printf("\n");
    printf("rbt_preorder:\n");
    rbt_preorder(b, print_key);
    rbt_free(b);
    return EXIT_SUCCESS;
    }*/
