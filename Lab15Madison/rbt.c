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

int rbt_search(rbt r, char *str){
    if (r == NULL){
        return 0;
    } else {
        if (strcmp(r->key, str) == 0){
            return 1;
        } else {
            if (strcmp(r->key, str) > 0){
                return rbt_search(r->left, str);
            } else {
                return rbt_search(r->right, str);
            }
        }
    }
}

rbt rbt_delete(rbt r, char *key){
    rbt temp;
    char *temp2;
    
    if (rbt_search(r, key) == 0){
        return r;
    } else {
        if (strcmp(r->key, key) == 0){
            if (r->left == NULL && r->right == NULL){
                free(r->key);
                free(r);
                /* b = NULL */
                return NULL;
            } else if ((r->left != NULL && r->right == NULL) ||
                       (r->right != NULL && r->left == NULL)){
                if (r->left != NULL){
                    temp = r->left;
                } else {
                    temp = r->right;
                }
                free(r->key);
                free(r);
                return temp;
            } else {
                temp = r->right;
                while (temp->left != NULL){
                    temp = temp->left;
                }
                temp2 = r->key;
                r->key = temp->key;
                temp->key = temp2;
                r->right = rbt_delete(r->right, temp->key);
                return r;
            }
        } else if (strcmp(r->key, key) > 0){
            r->left = rbt_delete(r->left, key);
            return r;
        } else {
            r->right = rbt_delete(r->right, key);
            return r;
        }
    }
}

rbt rbt_free(rbt r){
    if (r == NULL){
        return NULL;
    }
    rbt_free(r->left);
    rbt_free(r->right);
    free(r->key);
    free(r);

    return NULL;
}

void rbt_inorder(rbt r, void f(char *str)){
    if (r == NULL){
        return;
    } else {
        rbt_inorder(r->left, f);
        f(r->key);
        rbt_inorder(r->right, f);
        return;
    }
}

static rbt left_rotate(rbt r){
    rbt temp;

    temp = r;
    r = r->right;
    temp->right = r->left;
    r->left = temp;

    return r;
    
}

static rbt right_rotate(rbt r){
    rbt temp;

    temp = r;
    r = r->left;
    temp->left = r->right;
    r->right = temp;

    return r;
    
}

static rbt rbt_fix(rbt r){
    if (IS_RED(r->left) && IS_RED(r->left->left)){
        if (IS_RED(r->right)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        } else {
            r = right_rotate(r);
            r->colour = BLACK;
            r->right->colour = RED;
        }
    } else if (IS_RED(r->left) && IS_RED(r->left->right)){
        if (IS_RED(r->right)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        } else {
            r->left = left_rotate(r->left);
            r = right_rotate(r);
            r->colour = BLACK;
            r->right->colour = RED;
        }
    } else if (IS_RED(r->right) && IS_RED(r->right->left)){
        if (IS_RED(r->left)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        } else {
            r->right = right_rotate(r->right);
            r = left_rotate(r);
            r->colour = BLACK;
            r->left->colour = RED;
        }
    } else if (IS_RED(r->right) && IS_RED(r->right->right)){
        if (IS_RED(r->left)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        } else {
            r = left_rotate(r);
            r->colour = BLACK;
            r->left->colour = RED;
        }
    }
    return r;
}

rbt rbt_insert(rbt r, char *str){
    
    if (r == NULL){
        r = emalloc(sizeof *r);
        r->key = emalloc((strlen(str) + 1) * sizeof *str);
        r->left = rbt_new();
        r->right = rbt_new();
        r->colour = RED;
        strcpy(r->key, str);
        return r;
    } else {
        if (strcmp(r->key, str) == 0){ /* the same */
            return r;
        } else {
            if (strcmp(r->key, str) > 0){ /* key to be inserted is smaller */
                r->left = rbt_insert(r->left, str);
                r = rbt_fix(r);
                return r;
            } else {
                r->right = rbt_insert(r->right, str);
                r = rbt_fix(r);
                return r;
            }
        }
    }
}

void rbt_preorder(rbt r, void f(char *str)){
    if (r == NULL){
        return;
    } else {
        if (IS_RED(r)){
            printf("red: ");
        } else {
            printf("black: ");
        }
        f(r->key);
        rbt_preorder(r->left, f);
        rbt_preorder(r->right, f);
    }
}





