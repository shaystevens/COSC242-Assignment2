#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "bst.h"

struct bst_node {
    char *key;
    bst left;
    bst right;
};

bst bst_new(){
    return NULL;
}

int bst_search(bst b, char *str){
    if (b == NULL){
        return 0;
    } else {
        if (strcmp(b->key, str) == 0){
            return 1;
        } else {
            if (strcmp(b->key, str) > 0){
                return bst_search(b->left, str);
            } else {
                return bst_search(b->right, str);
            }
        }
    }
    
    
}

bst bst_delete(bst b, char *key){
    bst temp;
    char *temp2;
    
    if (bst_search(b, key) == 0){
        return b;
    } else {
        if (strcmp(b->key, key) == 0){
            if (b->left == NULL && b->right == NULL){
                free(b->key);
                free(b);
                /* b = NULL */
                return NULL;
            } else if ((b->left != NULL && b->right == NULL) ||
                       (b->right != NULL && b->left == NULL)){
                if (b->left != NULL){
                    temp = b->left;
                } else {
                    temp = b->right;
                }
                free(b->key);
                free(b);
                return temp;
            } else {
                temp = b->right;
                while (temp->left != NULL){
                    temp = temp->left;
                }
                temp2 = b->key;
                b->key = temp->key;
                temp->key = temp2;
                b->right = bst_delete(b->right, temp->key);
                return b;
            }
        } else if (strcmp(b->key, key) > 0){
            b->left = bst_delete(b->left, key);
            return b;
        } else {
            b->right = bst_delete(b->right, key);
            return b;
        }
    }
}

bst bst_free(bst b){
    if (b == NULL){
        return NULL;
    }
    bst_free(b->left);
    bst_free(b->right);
    free(b->key);
    free(b);

    return NULL;
}

void bst_inorder(bst b, void f(char *str)){
    if (b == NULL){
        return;
    } else {
        bst_inorder(b->left, f);
        f(b->key);
        bst_inorder(b->right, f);
        return;
    }
}

bst bst_insert(bst b, char *str){
    
    if (b == NULL){
        b = emalloc(sizeof *b);
        b->key = emalloc((strlen(str) + 1) * sizeof *str);
        b->left = bst_new();
        b->right = bst_new();
        strcpy(b->key, str);
        return b;
    } else {
        if (strcmp(b->key, str) == 0){ /* the same */
            return b;
        } else {
            if (strcmp(b->key, str) > 0){ /* key to be inserted is smaller */
                b->left = bst_insert(b->left, str);
                return b;
            } else {
                b->right = bst_insert(b->right, str);
                return b;
            }
        }
    }
}

void bst_preorder(bst b, void f(char *str)){
    if (b == NULL){
        return;
    } else {   
        f(b->key);
        bst_preorder(b->left, f);
        bst_preorder(b->right, f);
    }
}




