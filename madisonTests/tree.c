#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "tree.h"

#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))

/* THINGS TO DO IN THE TREE.C FILE 
   - TRY THE OUTPUT DOT FUNCTIONS
   - root node black done, though need to test with output dot function
 */
   

typedef enum { RED, BLACK } tree_colour;
static type_t tree_type;
static int no_insertion_calls = 0;
static tree root_node;

/* Tree structure */
struct tree_node {
    char *key;
    tree_colour colour;
    tree left;
    tree right;
    int frequency;
};

/**
 * Traverses the tree writing a DOT description about connections, and
 * possibly colours, to the given output stream.
 *
 * @param t the tree to output a DOT description of.
 * @param out the stream to write the DOT output to.
 */
static void tree_output_dot_aux(tree t, FILE *out) {
    if (t == NULL) {
        return;
    }
    if(t->key != NULL) {
        fprintf(out, "\"%s\"[label=\"{<f0>%s:%d|{<f1>|<f2>}}\"color=%s];\n",
                t->key, t->key, t->frequency,
                (RBT == tree_type && RED == t->colour) ? "red":"black");
    }
    if(t->left != NULL) {
        tree_output_dot_aux(t->left, out);
        fprintf(out, "\"%s\":f1 -> \"%s\":f0;\n", t->key, t->left->key);
    }
    if(t->right != NULL) {
        tree_output_dot_aux(t->right, out);
        fprintf(out, "\"%s\":f2 -> \"%s\":f0;\n", t->key, t->right->key);
    }
}

/**
 * Output a DOT description of this tree to the given output stream.
 * DOT is a plain text graph description language (see www.graphviz.org).
 * You can create a viewable graph with the command
 *
 *    dot -Tpdf < dotfile > dotfile.pdf
 *
 * where 'dotfile' is a file that has been written by tree_output_dot()
 *
 * You can also use png, ps, jpg, svg... instead of pdf
 *
 * @param t the tree to output the DOT description of.
 * @param out the stream to write the DOT description to.
 */
void tree_output_dot(tree t, FILE *out) {
    fprintf(out, "digraph tree {\nnode [shape = Mrecord, penwidth = 2];\n");
    tree_output_dot_aux(t, out);
    fprintf(out, "}\n");
}

/**
 * Creates a new tree using and uses the parameter to set the
 * type of tree it is.
 *
 * @param tree_version - type_t sets the tree type.
 *
 * @return returns NULL.
 */
tree tree_new(type_t tree_version){
    tree_type = tree_version;
    return NULL;
}

/**
 * Searches the tree for str returns 1 if found or 0 if not.
 *
 * @param t - type tree, the tree.
 * @param str - type char*, the string that is wanted to be found.
 *
 * @return int - 1 if string is in tree, 0 if it is not.
 */
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

/**
 * Frees the allocated memory of the tree.
 *
 * @param t - type tree, the tree.
 *
 * @return returns NULL.
 */
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

/*void tree_inorder(tree t, void f(char *str)){
    if (t == NULL){
        return;
    } else {
        tree_inorder(t->left, f);
        f(t->key);
        tree_inorder(t->right, f);
        return;
    }
    }*/

/**
 * Rotates the tree by shifting the the root down to the left.
 *
 * @param t - type tree, the tree.
 *
 * @return returns the tree.
 */
static tree left_rotate(tree t){
    tree temp;

    temp = t;
    t = t->right;
    temp->right = t->left;
    t->left = temp;

    return t;
    
}

/**
 * Rotates the tree by shifting the root down the side of the tree.
 *
 * @param t - type tree, the tree.
 *
 * @return returns the tree.
 */
static tree right_rotate(tree t){
    tree temp;

    temp = t;
    t = t->left;
    temp->left = t->right;
    t->right = temp;

    return t;
    
}

/**
 * Fixes the tree if it is breaking RBT rules.
 *
 * @param t - type tree, the tree.
 *
 * @return returns the fixed tree.
 */
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
    if (t == root_node){
        t->colour = BLACK;
    }
    return t;
}

/**
 * Inserts string into the tree.
 *
 * @param t - type tree, the tree.
 * @param str - type char*, the string to be inserted into the tree.
 *
 * @return returns the string.
 */
tree tree_insert(tree t, char *str){
    
    if (t == NULL){
        t = emalloc(sizeof *t);
        t->key = emalloc((strlen(str) + 1) * sizeof *str);
        t->left = tree_new(tree_type);
        t->right = tree_new(tree_type);
        /* MUST BE BLACK IF ROOT NODE FIX!!! */
        if (tree_type == RBT){
            t->colour = RED;
        }
        strcpy(t->key, str);
        t->frequency++;
        if (no_insertion_calls == 0){
            root_node = t;
            no_insertion_calls++;
        }
        return t;
    } else {
        if (strcmp(t->key, str) == 0){ /* the same */
            t->frequency++;
            return t;
        } else {
            if (strcmp(t->key, str) > 0){ /* key to be inserted is smaller */
                t->left = tree_insert(t->left, str);
                if (tree_type == RBT){
                    t = tree_fix(t);
                }
                return t;
            } else {
                t->right = tree_insert(t->right, str);
                if (tree_type == RBT){
                    t = tree_fix(t);
                }
                return t;
            }
        }
    }
}

void tree_preorder(tree t, void f(int freq, char *str)){
    if (t == NULL){
        return;
    } else {
        /* NEED TO MAKE IT SO THAT ROOT NODE IS ALWAYS BLACK AFTER FIX UP
          if (tree_type == RBT){
            if (IS_RED(t)){
                printf("red: ");
            } else {
                printf("black: ");
            }
            }*/
        f(t->frequency, t->key);
        tree_preorder(t->left, f);
        tree_preorder(t->right, f);
    }
}

/**
 * Find the depth of the given tree.
 *
 * @param t - type tree, the tree.
 *
 * @return int - return the depth of the tree.
 */
int tree_depth(tree t){
    int max_count = 0;
    int left_depth = -1;
    int right_depth = -1;
    if (t == NULL){
        return -1;
    } else {
        if (t->left == NULL && t->right == NULL){
            return 0;
        } else {
            left_depth = tree_depth(t->left);
            right_depth = tree_depth(t->right);
            if (left_depth > right_depth){
                return max_count = left_depth + 1; 
            } else {
                return max_count = right_depth + 1;
            }
        }
    }
}



