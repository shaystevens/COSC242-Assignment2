#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "rbt.h"
#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))

typedef enum { RED, BLACK } rbt_colour;

struct rbt_node {
char *key;
  rbt_colour colour;
  rbt left;
  rbt right;
};

 rbt rbt_new(){
    return NULL;
}

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
    /* cases of consecuitve reds below root */
    if(IS_RED(r->left) && IS_RED(r->left->left)){
        if(IS_RED(r->right)){
            r->colour = RED;
            r->right->colour = BLACK;
            r->left->colour = BLACK;

        }else if(IS_BLACK(r->right)){
            r = right_rotate(r);
            r->colour = BLACK;
            r->right->colour = RED;
        }
    }
        else if(IS_RED(r->left) && (r->left->right)){
            if(IS_RED(r->right)){
                r->colour = RED;
                r->left->colour = BLACK;
                r->right->colour = BLACK;

            }else if(IS_BLACK(r->right)){
                r->left = left_rotate(r->left); 
                r =right_rotate(r);
                r->colour = BLACK;
                r->right->colour = RED;
            }
        }
        else if(IS_RED(r->right) && IS_RED(r->right->left)){
            if(IS_RED(r->left)){
                r->colour = RED;
                r->left->colour = BLACK;
                r->right->colour = BLACK;

            }else if(IS_BLACK(r->left)){
                r->right = right_rotate(r->right);
                r =left_rotate(r);
                r->colour = BLACK;
                r->left->colour = RED;
            }
        }
        else if(IS_RED(r->right) && IS_RED(r->right->right)){
            if(IS_RED(r->left)){
                r->colour = RED;
                r->right->colour = BLACK;
                r->left->colour = BLACK;

            }else if(IS_BLACK(r->left)){
                r= left_rotate(r);
                r->colour = BLACK;
                r->left->colour = RED;
            }
        }
        return r;
}


rbt rbt_insert(rbt r, char *str){
    if(r == NULL){
        r = malloc(sizeof(struct rbt_node));
        r->key = malloc((strlen(str)+1) * sizeof(char));
        strcpy(r->key, str);
        return r;
    }else if(strcmp(str, r->key) == 0){
        r = rbt_fix(r);
        return r;
    }else if(strcmp(str, r->key) < 0){
        r->left = rbt_insert(r->left, str);
        r = rbt_fix(r);
        return r;
    }else if(strcmp(str, r->key) > 0){
        r->right = rbt_insert(r->right, str);
        r = rbt_fix(r);
        return r;
    }
    return r;
}

rbt rbt_free(rbt r){
    if(r == NULL){
        return NULL;
    }  
    rbt_free(r->right);
    rbt_free(r->left);
    free(r);
    free(r->key);
    return r;
}

void rbt_inorder(rbt r, void f(char *str)){
    if(r == NULL){
        return;
    }
        rbt_inorder(r->left, f);
        if(r->colour == BLACK || IS_BLACK(r)) {
        printf("black: ");
    }
    else if(r->colour == RED || IS_RED(r)){
        printf("red: ");
    }
    f(r->key);
        rbt_inorder(r->right, f);
}

void rbt_preorder(rbt r, void f(char *str)){
     if(r == NULL){
        return;
     }
    
    if(r->colour == BLACK || IS_BLACK(r)) {
        printf("black: ");
    }
    else if(r->colour == RED || IS_RED(r)){
        printf("red: ");
    }
        f(r->key);
        rbt_preorder(r->left, f);
        rbt_preorder(r->right, f);
    }

rbt rbt_delete(rbt r, char *str){
    if (r == NULL || 0 == rbt_search(r, str)){
        return NULL;
    }
        else if(strcmp(r->key, str) > 0){
        r->left = rbt_delete(r->left, str);
        }

        else if(strcmp(r->key, str) < 0){
        r->right = rbt_delete(r->right, str);
        }
        /* if the node to re deleted is a leaf */
       else if (r->right == NULL && r->left == NULL){
            free(r->key);
            free(r);
            r = NULL;
            return r;
        }
        /* if node to re deleted has one child */
        else if(r->right == NULL){
            free(r->key);
            free(r);
            r = r->left;
            return r;
        }
        else if(r->left == NULL){
            free(r->key);
            free(r);
            r = r->right;
            return r;
        }
         /* if the node has two children, find leftmost child of right 
        * subtree and swap its keys. Then delete the key from right subtree.
        */

        else{
            rbt copy = r->right;
            while (copy->left != NULL){
                copy = copy->left;
            }
            strcpy(r->key, copy->key);
            r->right = rbt_delete(r->right, copy->key);
            return r;
        }
        return r;
    }

int rbt_search(rbt r, char *str){
    if(r == NULL){
        return 0;
    }else{
        if(strcmp(r->key, str) == 0){
        return 1;
    }else{
        if(strcmp(str, r->key) > 0){
       return rbt_search(r->right, str);
    }else{
       return rbt_search(r->left, str);
            }
        }
    }
}



