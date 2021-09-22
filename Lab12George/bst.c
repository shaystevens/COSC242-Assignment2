#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "bst.h"

struct bstnode {
    char *key;
    bst left;
    bst right;
};

 bst bst_new(){
    return NULL;
}

bst bst_free(bst b){
    if(b == NULL){
        return NULL;
    }  
    bst_free(b->right);
    bst_free(b->left);
    free(b);
    free(b->key);
    return b;
}

int bst_search(bst b, char *str){
    if(b == NULL){
        return 0;
    }else{
        if(strcmp(b->key, str) == 0){
        return 1;
    }else{
        if(strcmp(str, b->key) > 0){
       return bst_search(b->right, str);
    }else{
       return bst_search(b->left, str);
            }
        }
    }
}

bst bst_insert(bst b, char *str){
    if(b == NULL){
        b = emalloc(sizeof(struct bstnode));
        b->key = emalloc((strlen(str)+1) * sizeof(char));
        strcpy(b->key, str);
        return b;
    }else if(strcmp(str, b->key) == 0){
        return b;
    }else if(strcmp(str, b->key) < 0){
        b->left = bst_insert(b->left, str);
        return b;
    }else if(strcmp(str, b->key) > 0){
        b->right = bst_insert(b->right, str);
        return b;
    }
    return b;
}

void bst_inorder(bst b, void f(char *str)){
    if(b == NULL){
        return;
    }
    bst_inorder(b->left, f);
    f(b->key);
    bst_inorder(b->right, f);
}

void bst_preorder(bst b, void f(char *str)){
    if(b == NULL){
        return;
    }
        f(b->key);
        bst_preorder(b->left, f);
        bst_preorder(b->right, f);
    }

bst bst_delete(bst b, char *str){
    if (b == NULL || 0 == bst_search(b, str)){
        return NULL;
    }
        else if(strcmp(b->key, str) > 0){
        b->left = bst_delete(b->left, str);
        }

        else if(strcmp(b->key, str) < 0){
        b->right = bst_delete(b->right, str);
        }
        /* if the node to be deleted is a leaf */
       else if (b->right == NULL && b->left == NULL){
            free(b->key);
            free(b);
            b = NULL;
            return b;
        }
        /* if node to be deleted has one child */
        else if(b->right == NULL){
            free(b->key);
            free(b);
            b = b->left;
            return b;
        }
        else if(b->left == NULL){
            free(b->key);
            free(b);
            b = b->right;
            return b;
        }
         /* if the node has two children, find leftmost child of right 
        * subtree and swap its keys. Then delete the key from right subtree.
        */

        else{
            bst copy = b->right;
            while (copy->left != NULL){
                copy = copy->left;
            }
            strcpy(b->key, copy->key);
            b->right = bst_delete(b->right, copy->key);
            return b;
        }
        return b;
    }
