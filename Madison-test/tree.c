#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "tree.h"

#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))


typedef enum { RED, BLACK } tree_colour;
static type_t tree_type;

struct tree_node {
    char *key;
    tree_colour colour;
    tree left;
    tree right;
    int *frequency;
};

tree tree_new(type_t tree_version){
    tree_type = tree_version;
    return NULL;
}

int tree_search(tree t, char *str){
    if (t == NULL){
        return 0;
    } else {
        if (strcmp(t->key, str) == 0){
            return 1;
        } else {
            if (strcmp(t->key, str) > 0){
                return tree_search(t->left, str);
            } else {
                return tree_search(t->right, str);
            }
        }
    }
}

tree tree_free(tree t){
    if (t == NULL){
        return NULL;
    }
    tree_free(t->left);
    tree_free(t->right);
    free(t->key);
    free(t);

    return NULL;
}

void tree_inorder(tree t, void f(char *str)){
    if (t == NULL){
        return;
    } else {
        tree_inorder(t->left, f);
        f(t->key);
        tree_inorder(t->right, f);
        return;
    }
}

static tree left_rotate(tree t){
    tree temp;

    temp = t;
    t = t->right;
    temp->right = t->left;
    t->left = temp;

    return t;
    
}

static tree right_rotate(tree t){
    tree temp;

    temp = t;
    t = t->left;
    temp->left = t->right;
    t->right = temp;

    return t;
    
}

static tree tree_fix(tree t){
    if (IS_RED(t->left) && IS_RED(t->left->left)){
        if (IS_RED(t->right)){
            t->colour = RED;
            t->left->colour = BLACK;
            t->right->colour = BLACK;
        } else {
            t = right_rotate(t);
            t->colour = BLACK;
            t->right->colour = RED;
        }
    } else if (IS_RED(t->left) && IS_RED(t->left->right)){
        if (IS_RED(t->right)){
            t->colour = RED;
            t->left->colour = BLACK;
            t->right->colour = BLACK;
        } else {
            t->left = left_rotate(t->left);
            t = right_rotate(t);
            t->colour = BLACK;
            t->right->colour = RED;
        }
    } else if (IS_RED(t->right) && IS_RED(t->right->left)){
        if (IS_RED(t->left)){
            t->colour = RED;
            t->left->colour = BLACK;
            t->right->colour = BLACK;
        } else {
            t->right = right_rotate(t->right);
            t = left_rotate(t);
            t->colour = BLACK;
            t->left->colour = RED;
        }
    } else if (IS_RED(t->right) && IS_RED(t->right->right)){
        if (IS_RED(t->left)){
            t->colour = RED;
            t->left->colour = BLACK;
            t->right->colour = BLACK;
        } else {
            t = left_rotate(t);
            t->colour = BLACK;
            t->left->colour = RED;
        }
    }
    return t;
}

tree tree_insert(tree t, char *str){
    
    if (t == NULL){
        t = emalloc(sizeof *r);
        t->key = emalloc((strlen(str) + 1) * sizeof *str);
        t->left = tree_new();
        t->right = tree_new();
        t->colour = RED;
        strcpy(t->key, str);
        return t;
    } else {
        if (strcmp(t->key, str) == 0){ /* the same */
            return t;
        } else {
            if (strcmp(t->key, str) > 0){ /* key to be inserted is smaller */
                t->left = tree_insert(t->left, str);
                t = tree_fix(t);
                return t;
            } else {
                t->right = tree_insert(t->right, str);
                t = tree_fix(t);
                return t;
            }
        }
    }
}

void tree_preorder(tree t, void f(char *str)){
    if (t == NULL){
        return;
    } else {
        if (IS_RED(t)){
            printf("red: ");
        } else {
            printf("black: ");
        }
        f(t->key);
        tree_preorder(t->left, f);
        tree_preorder(t->right, f);
    }
}





