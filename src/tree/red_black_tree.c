#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "red_black_tree.h"

I32_Rb_Node* i32_rb_node_new(int root_val) {
    I32_Rb_Node* root = (I32_Rb_Node*) malloc(sizeof(I32_Rb_Node));
    if(root == NULL) {
        printf("Unable to allocate memory for the red black tree root node.");
        exit(1);
    }

    root->parent = NULL;
    root->left   = NULL;
    root->right  = NULL;
    root->val    = root_val;
    root->color  = NODE_BLACK;
    return root;
}

void i32_rb_node_free(I32_Rb_Node* root) {
    free(root);
    // TODO
}

void i32_rb_node_insert(I32_Rb_Node* root, int value) {
    // Inset like binary search tree.
    // Fix violations.
}