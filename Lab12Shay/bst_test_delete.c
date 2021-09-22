#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void print_key(char *key) {
    printf("%s\n", key);
}

void dosearch(bst b, char *key) {
    if (bst_search(b, key)) {
        printf("%s -- found\n", key);
    } else {
        printf("%s -- not found\n", key);
    }
}

int main(void) {
    bst b = bst_new();

    printf("inserting d,b,f,a,c,e,g\n");
    b = bst_insert(b, "d");
    b = bst_insert(b, "b");
    b = bst_insert(b, "f");
    b = bst_insert(b, "a");
    b = bst_insert(b, "c");
    b = bst_insert(b, "e");
    b = bst_insert(b, "g");
    /*
                d
             /      \
            /        \
           b          f
          / \        / \
         /   \      /   \
        a     c    e     g
     */

    printf("inorder traversal\n");
    bst_inorder(b, print_key);

    printf("preorder traversal\n");
    bst_preorder(b, print_key);

    b = bst_delete(b, "a");
    printf("inorder traversal\n");
    printf("bcdefg\n");
    bst_inorder(b, print_key);
    /*
               d
            /      \
           /        \
          b          f
           \        / \
            \      /   \
             c    e     g
    */
    
    b = bst_delete(b, "b");
    printf("inorder traversal\n");
    printf("cdefg\n");
    bst_inorder(b, print_key);
    /*
              d
           /      \
          /        \
         c          f
                   / \
                  /   \
                 e     g
    */

    b = bst_delete(b, "f");
    printf("inorder traversal\n");
    printf("cdeg\n");
    bst_inorder(b, print_key);
    /*
             d
           /    \
          /      \
         c        g
                 /
                /
               e 
    */
    
    printf("searching\n");
    dosearch(b, "f");
    dosearch(b, "o");
    dosearch(b, "x");
    dosearch(b, "e");
    dosearch(b, "d");
   
    bst_free(b);
    return EXIT_SUCCESS;
}
