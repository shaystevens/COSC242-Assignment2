#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbt.h"
#include "mylib.h"

#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))

struct rbt_node {
    char *key;
    rbt_colour colour;
    rbt left;
    rbt right;
};

static rbt right_rotate(rbt r){
    rbt temp = r;
    r = r->left;
    temp->left = r->right;
    r->right = temp;
    return r;
}

static rbt left_rotate(rbt r){
    rbt temp = r;
    r = r->right;
    temp->right = r->left;
    r->left = temp;
    return r;
}

static rbt rbt_fix(rbt r){
    if(IS_RED(r->left) && IS_RED(r->left->left)){
        if(IS_RED(r->right)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        }else{
            r = right_rotate(r);
            r->colour = BLACK;
            r->right->colour = RED;
        }
    }else if(IS_RED(r->left) && IS_RED(r->left->right)){
        if(IS_RED(r->right)){
                r->colour = RED;
                r->left->colour = BLACK;
                r->right->colour = BLACK;
        }else{
            r->left = left_rotate(r->left);
            r = right_rotate(r);
            r->colour = BLACK;
            r->right->colour = RED;
        }
    }else if(IS_RED(r->right) && IS_RED(r->right->left)){
        if(IS_RED(r->left)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        }else{
            r->right = right_rotate(r->right);
            r = left_rotate(r);
            r->colour = BLACK;
            r->left->colour = RED;
        }
    }else if(IS_RED(r->right) && IS_RED(r->right->right)){
        if(IS_RED(r->left)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        }else{
            r = left_rotate(r);
            r->colour = BLACK;
            r->left->colour = RED;
        }
    }

    return r;
}

rbt rbt_new(){
    return NULL;
}

rbt rbt_free(rbt r){
    if(r != NULL){
        rbt_free(r->left);
        rbt_free(r->right);
        free(r->key);
        free(r);
        return NULL;
    }
    return NULL;
}

rbt rbt_insert(rbt r, char *str){
    if(r==NULL){
        r = emalloc(sizeof *r);
        r->key = emalloc((strlen(str+1)) * sizeof (char));
        r->colour = RED;
        r->left = NULL;
        r->right = NULL;
        strcpy(r->key, str);
    }else{
        if((strcmp(str, r->key)) < 0){
            r->left = rbt_insert(r->left, str);
        }else{
            r->right = rbt_insert(r->right, str);
        }
    }
    r = rbt_fix(r);
    return r;
}

rbt rbt_delete(rbt r, char *str){
    if(r == NULL || rbt_search(r, str) == 0){
        return r;
    }

    if(strcmp(r->key, str) == 0){
        if(r->left == NULL && r->right == NULL){
            free(r->key);
            free(r);
            r = NULL;
        }else if(r->left != NULL && r->right != NULL){
            rbt copy = r->right;
            char *temp;
            
            while(copy->left != NULL){
                copy = copy->left;
            }
            temp = r->key;
            r->key = copy->key;
            copy->key = temp;
            r->right = rbt_delete(r->right, temp);
        }else{
            if(r->left != NULL){
                free(r->key);
                free(r);
                r = r->right;
            }else{
                free(r->key);
                free(r);
                r = r->right;
            }
        }
    }else if(strcmp(str, r->key) < 0){
        r->left = rbt_delete(r->left, str);
        
    }else{
        r->right = rbt_delete(r->right, str);
    }
    return r;     
}

void rbt_inorder(rbt r, void f(char *str)){
    if(r != NULL){
        rbt_inorder(r->left,f);
        if(IS_BLACK(r)){
            printf("Black: ");
        }
        else printf("Red: ");
        f(r->key);
        rbt_inorder(r->right,f);
    }
    return;
}

void rbt_preorder(rbt r, void f(char *str)){
    if(r!=NULL){

        if(IS_BLACK(r)){
            printf("Black: ");
        }
        else printf("Red: ");
        f(r->key);
        rbt_preorder(r->left,f);
        rbt_preorder(r->right,f);
    }
    return;
}

int rbt_search(rbt r, char *str){
    if(r == NULL){
        return 0;
    }else if((strcmp(r->key, str)) == 0){
        return 1;
    }else if((strcmp(str, r->key)) < 0){
        return rbt_search(r->left, str);
    }else{
        return rbt_search(r->right, str);
    }
}
