#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"
#include "mylib.h"

void print_key(char *s){
    printf("%s\n", s);
}
int main(void) {
    rbt r = rbt_new();

    printf("Inserting...\n\n");
    r = rbt_insert(r, "h");
    r = rbt_insert(r, "l");
    r = rbt_insert(r, "i");
    r = rbt_insert(r, "f");
    r = rbt_insert(r, "j");
    r = rbt_insert(r, "g");
    r = rbt_insert(r, "k");
    r = rbt_insert(r, "d");
    r = rbt_insert(r, "a");
    r = rbt_insert(r, "e");
    r = rbt_insert(r, "b");
    r = rbt_insert(r, "c");
    
    printf("*** Inorder ***\n");
    rbt_inorder(r, print_key);
    printf("\n*** Preorder ***\n");
    rbt_preorder(r,print_key);
    
    rbt_free(r);
    return EXIT_SUCCESS;
}  
