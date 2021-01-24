#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>

/*treenode type defined as tree pointer*/
typedef struct treenode *tree;
/*enumerated type for node colour*/
typedef enum {BLACK,RED} tree_colour;
/*enumerated type for tree type*/
typedef enum tree_e {BST, RBT} tree_t;

/*Functions implemented in tree.c*/
extern tree tree_free(tree r);
extern tree tree_insert(tree r, char *str);
extern tree tree_new(tree_t t);
extern void tree_preorder(tree r, void f(int freq, char *str));
extern int tree_search(tree r, char *str);
extern tree tree_colour_flip(tree b);
extern int tree_depth(tree b);
extern void tree_output_dot(tree t, FILE *out);

#endif
