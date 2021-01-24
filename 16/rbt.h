#ifndef RBT_H_
#define RBT_H_

typedef struct rbtnode *rbt;

typedef enum {BLACK,RED} rbt_colour;

extern rbt rbt_delete(rbt r, char *str);
extern rbt rbt_free(rbt r);
extern void rbt_inorder(rbt r, void f(char *str));
extern rbt rbt_insert(rbt r, char *str);
extern rbt rbt_new();
extern void rbt_preorder(rbt r, void f(char *str));
extern int rbt_search(rbt r, char *str);
extern rbt right_rotate(rbt b);
extern rbt left_rotate(rbt b);
extern rbt rbt_fix(rbt b);

#endif
