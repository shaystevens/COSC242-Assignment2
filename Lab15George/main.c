#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"

void search(rbt r, char *key){
     if(rbt_search(r, key)){
         printf("The %s Found key! \n \n", key);
     } else { 
         printf("The %s Key not found! \n \n", key);
     }
 }

void print_key(char *key) {
    printf("%s\n", key);
}

int main(void){
    rbt r = rbt_new();

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
    printf("___________________________________________________________________________________________");
    printf("\n----testing insert function, inserted h, l, i, f, j, g, k, d, a, e, b, and c---- \n \n");
    

    printf("----testing delete function, deleting c only---- \n \n");
    rbt_delete(r, "c");

    printf("----now testing search function. search for h,l and xc---- \n \n"); 
    search(r, "h");
    search(r, "l");
    search(r, "c");
    
    
    
    printf("----testing inodrer function.---- \n \n");
    rbt_inorder(r, print_key);

    printf("\n----testing preorder function---- \n \n");
    rbt_preorder(r, print_key);
    printf("\n");
    printf("----program finished deallocating memory in data structure----\n");
    printf("___________________________________________________________________________________________");
    rbt_free(r);

    return EXIT_SUCCESS;
}
