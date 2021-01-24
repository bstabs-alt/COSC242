#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbt.h"
#include "mylib.h"

#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x) -> colour))
#define IS_RED(x) ((NULL !=(x)) && (RED == (x) -> colour))


struct rbtnode{
    char *key;
    rbt left;
    rbt right;
    rbt_colour colour;
};

rbt right_rotate (rbt b){
    rbt temp = b;
    b= b-> left;
    temp -> left = b->right;
    b->right = temp;
    return b;
}

rbt left_rotate (rbt b){
    rbt temp = b;
    b = b-> right;
    temp -> right = b->left;
    b-> left = temp;
    return b;
}

rbt rbt_fix (rbt b){
    if (IS_RED(b->left) && IS_RED(b->left->left)){
        if (IS_RED(b->right)){
            b->colour = RED;
            b->left->colour = BLACK;
            b->right->colour = BLACK;
        } else {
            b = right_rotate(b);
            
            b->colour = BLACK;
            b->right->colour = RED;
        }
    } else if (IS_RED(b->left) && IS_RED(b->left->right)){
        if (IS_RED(b->right)){
            b->colour = RED;
            b->left->colour = BLACK;
            b->right->colour = BLACK;
        } else {
            b->left = left_rotate(b->left);
            b = right_rotate(b);
            
            b->colour = BLACK;
            b->right->colour = RED;
        }
    } else if (IS_RED(b->right) && IS_RED(b->right->left)){
        if (IS_RED(b->left)){
            b->colour = RED;
            b->left->colour = BLACK;
            b->right->colour = BLACK;
        } else {
            b->right = right_rotate(b->right);
            b = left_rotate(b);
            
            b->colour = BLACK;
            b->left->colour = RED;
        }
    } else if (IS_RED(b->right) && IS_RED(b->right->right)){
        if (IS_RED(b->left)){
            b->colour = RED;
            b->left->colour = BLACK;
            b->right->colour = BLACK;
        } else {
            b = left_rotate(b);
            
            b->colour = BLACK;
            b->left->colour = RED;
        }
    }
    return b;
} 

rbt rbt_new(){
    return NULL;
}

rbt rbt_delete(rbt b, char *str){
    if (b->key == NULL) {
        return b;
    } else if (strcmp(b->key, str) > 0) {
        rbt_delete(b->left, str);
    } else if (strcmp(b->key, str) < 0) {
        rbt_delete(b->right, str);
    } else if (strcmp(b->key, str) == 0) {
        if(b->left == NULL && b->right == NULL){
            free(b->key);
            free(b);
            b = NULL;
        } else if(b->left == NULL){
            free(b->key);
            free(b);
            b = b->right;
        } else if(b->right == NULL){
            free(b->key);
            free(b);
            b = b->left;
        } else{
            rbt copy = b->right;
            char *temp;
            while(copy->left !=NULL){
                copy = copy->left;
            }
            temp = b->key;
            b->key = copy->key;
            copy->key = temp;
            b->right = rbt_delete(b->right, temp);
        }
    }
    return b;
}


rbt rbt_free(rbt b){
    if(b == NULL){
        return b;
    }
    free(b->key);
    free(b->left);
    free(b->right);
    free(b);
    return b;
}

void rbt_inorder(rbt b, void f(char *str)){
    if(b == NULL) {
        return; 
    } 
    rbt_inorder(b->left, f); 
    f(b->key);
    rbt_inorder(b->right, f);
}

rbt rbt_insert(rbt b, char *str){
    if(b == NULL){
        b = emalloc(sizeof * b);
        b->key = emalloc(strlen(str)-1);
        b-> colour = RED;
        b-> right = NULL;
        b->left = NULL;
        strcpy(b->key, str);
    }
    else if (strcmp(str, b->key) < 0) {
        b->left = rbt_insert(b->left, str);
    }
    else if(strcmp(str, b->key) > 0){
        b->right = rbt_insert(b->right, str);
    }
    b = rbt_fix(b);
    return b; 
}

void rbt_preorder(rbt b, void f(char *str)){
    if(b == NULL){
        return;
    }
    f(b->key);
    rbt_preorder(b->left, f);
    rbt_preorder(b->right,f);
}

int rbt_search(rbt b, char *str){
    if (b->key == NULL) {
        return 0; 
    }
    else if (strcmp(b->key, str) == 0) { 
        return 1;
    } else if (strcmp(b->key, str) > 0){ 
        rbt_search(b->left, str);
    } else {
        rbt_search(b->right, str);
    }
    return 0;
}
