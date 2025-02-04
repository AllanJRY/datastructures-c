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
    if (root->val > value) {
        if (root->left == NULL) {
            I32_Rb_Node* new_left = i32_rb_node_new(value);
            new_left->color       = NODE_RED;
            new_left->parent      = root;
            root->left            = new_left;
        } else {
            i32_rb_node_insert(root->left, value);
        }
    } else {
        if (root->right == NULL) {
            I32_Rb_Node* new_right = i32_rb_node_new(value);
            new_right->color       = NODE_RED;
            new_right->parent      = root;
            root->right            = new_right;
        } else {
            i32_rb_node_insert(root->right, value);
        }
    }

    // Fix violations.
    // If parent is black
        // No violations, return.
    // otherwise
        // if uncle is also red
            // recolor parent and uncle to black
            // if grandparent is not root
                // recolor grandparent to red
                // check for rule violations
        // else uncle is black
            // Perform rotation :
            // if left-left or right-right
                // parent become black and take the place of grandparent
                // grandparent become red and child of parent
            // if left-right or right-left
                // new node become grandparent and black
                // grandparent become child of new node and red


}