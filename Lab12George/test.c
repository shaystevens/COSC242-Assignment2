#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void search(bst b, char *key){
     if(bst_search(b, key)){
         printf("The %s Found key! \n \n", key);
     } else { 
         printf("The %s Key not found! \n \n", key);
     }
 }

void print_key(char *key) {
    printf("%s\n", key);
}

int main(void){
    bst b = bst_new();

    b = bst_insert(b, "i");
    b = bst_insert(b, "n");
    b = bst_insert(b, "s");     
    b = bst_insert(b, "e"); 
    b = bst_insert(b, "r");  
    b = bst_insert(b, "t"); 
    printf("\n----testing insert function, inserted i,n,s,e,r,t---- \n \n");
    

    printf("----testing delete function, deleting i,n---- \n \n");
    bst_delete(b, "i");
    bst_delete(b, "n");

    printf("----now testing search function. search for i,n,s ---- \n \n"); 
    search(b, "i");
    search(b, "n");
    search(b, "s");
    
    
    
    printf("----testing inodrer function.---- \n \n");
    bst_inorder(b, print_key);

    printf("\n----testing preorder function---- \n \n");
    bst_preorder(b, print_key);
    printf("\n");
    printf("----program finished deallocating memory in data structure----\n");
    bst_free(b);

    return EXIT_SUCCESS;
}
