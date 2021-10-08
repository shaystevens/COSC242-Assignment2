/**
* @file tree.h
* @author Madison Wong, George Churton, Shay Stevens.
* 
* PURPOSE - tree.h holds function prototypes as well as the headers for
* the tree program. The file also defines the struct of tree.
*/

#ifndef TREE_H_
#define TREE_H_

typedef enum tree_e { BST, RBT } type_t;
typedef struct tree_node *tree;

extern tree  tree_delete(tree t, char *str);
extern tree tree_free(tree t);
extern tree tree_insert(tree t, char *str);
extern tree tree_new(type_t tree_type);
extern void tree_preorder(tree t, void f(int freq, char *str));
extern int tree_search(tree t, char *str);
extern int tree_depth(tree t);
extern void tree_output_dot(tree t, FILE *out);

#endif
