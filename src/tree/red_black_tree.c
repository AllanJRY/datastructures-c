#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "red_black_tree.h"

static Rb_Node_Color node_color(Rb_Node* node) {
    if (node == NULL) { return NODE_BLACK; }
    return node->color;
}

static void fix_violations(Rb_Node* node) {
    while (node->color == NODE_RED) {
        Rb_Node* parent_node = node->parent;
        if (node_color(parent_node) == NODE_BLACK) {
            // No violations, return.
            return;
        } else {
            Rb_Node* grand_parent_node = parent_node->parent;
            Rb_Node* uncle_node = grand_parent_node->left != parent_node ? grand_parent_node->left : grand_parent_node->right;

            if (node_color(uncle_node) == NODE_RED) {
                // recolor parent and uncle to black
                parent_node->color = NODE_BLACK;
                uncle_node->color  = NODE_BLACK;

                // if grandparent is not root
                if (grand_parent_node->parent != NULL) {
                    grand_parent_node->color = NODE_RED;
                    node = grand_parent_node; 
                    continue; // Continue to check for new violations
                }
            } else {
                // Perform rotation :
                // if left-left or right-right
                    // parent become black and take the place of grandparent
                    // grandparent become red and child of parent
                // if left-right or right-left
                    // new node become grandparent and black
                    // grandparent become child of new node and red
            }
        }
    }
}

Rb_Node* rb_node_new(int root_val, bool is_root) {
    Rb_Node* root = (Rb_Node*) malloc(sizeof(Rb_Node));
    if(root == NULL) {
        printf("Unable to allocate memory for the red black tree root node.");
        exit(1);
    }

    root->parent = NULL;
    root->left   = NULL;
    root->right  = NULL;
    root->val    = root_val;
    root->color  = is_root ? NODE_BLACK : NODE_RED;
    return root;
}

void rb_node_free(Rb_Node* root) {
    free(root);
    // TODO
}


void rb_node_insert(Rb_Node* root, int val) {
    // Inset like binary search tree.
    Rb_Node* parent_node = root;
    Rb_Node* child_node = parent_node->val > val ? parent_node->left : parent_node->right;
    while(child_node != NULL) {
        parent_node = child_node;
        child_node = parent_node->val > val ? parent_node->left : parent_node->right;
    }

    // TODO: What to do when val equals ?
    if(parent_node->val > val) {
        parent_node->left         = rb_node_new(val, false);
        parent_node->left->parent = parent_node;
        child_node = parent_node->left;
    } else {
        parent_node->right         = rb_node_new(val, false);
        parent_node->right->parent = parent_node;
        child_node = parent_node->right;
    }

    fix_violations(child_node);
}