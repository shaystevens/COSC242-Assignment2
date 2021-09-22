#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "mylib.h"

struct bstnode {
    char *key;
    bst left;
    bst right;
};

bst bst_new(){
    return NULL;
}

bst bst_free(bst b){
    if(b != NULL){
        bst_free(b->left);
        bst_free(b->right);
        free(b->key);
        free(b);
        return NULL;
    }
    return NULL;
}

bst bst_insert(bst b, char *str){
    if(b==NULL){
        bst result = emalloc(sizeof *result);
        result->key = emalloc((strlen(str+1)) * sizeof (char));
        result->left = NULL;
        result->right = NULL;
        strcpy(result->key, str);
        return result;
    }else{
        if((strcmp(str, b->key)) < 0){
            b->left = bst_insert(b->left, str);
        }else{
            b->right = bst_insert(b->right, str);
        }
    }
    return b;
}

bst bst_delete(bst b, char *str){
    if(b == NULL || bst_search(b, str) == 0){
        return b;
    }

    if(strcmp(b->key, str) == 0){
        if(b->left == NULL && b->right == NULL){
            free(b->key);
            free(b);
            b = NULL;
        }else if(b->left != NULL && b->right != NULL){
            bst copy = b->right;
            char *temp;
            
            while(copy->left != NULL){
                copy = copy->left;
            }
            temp = b->key;
            b->key = copy->key;
            copy->key = temp;
            b->right = bst_delete(b->right, temp);
        }else{
            if(b->left != NULL){
                free(b->key);
                free(b);
                b = b->right;
            }else{
                free(b->key);
                free(b);
                b = b->right;
            }
        }
    }else if(strcmp(str, b->key) < 0){
        b->left = bst_delete(b->left, str);
        
    }else{
        b->right = bst_delete(b->right, str);
    }
    return b;     
}

void bst_inorder(bst b, void f(char *str)){
    if(b != NULL){
        bst_inorder(b->left, f);
        f(b->key);
        bst_inorder(b->right, f);
    }
    return;
}

void bst_preorder(bst b, void f(char *str)){
    if(b != NULL){
        f(b->key);
        bst_preorder(b->left, f);
        bst_preorder(b->right, f);
    }
    return;
}

int bst_search(bst b, char *str){
    if(b == NULL){
        return 0;
    }else if((strcmp(b->key, str)) == 0){
        return 1;
    }else if((strcmp(str, b->key)) < 0){
        return bst_search(b->left, str);
    }else{
        return bst_search(b->right, str);
    }
}


