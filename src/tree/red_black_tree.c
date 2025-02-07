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
                bool node_is_left        = parent_node->left == node;
                bool parent_node_is_left = grand_parent_node->left == parent_node;
                // TODO Check rotation name if it is not inversed.
                // + Refactor, some logics can be shared between rotations.
                if (node_is_left && parent_node_is_left) {
                    // Right rotation
                    parent_node->parent             = grand_parent_node->parent;
                    grand_parent_node->parent->left = parent_node;
                    grand_parent_node->left         = parent_node->right;
                    grand_parent_node->parent       = parent_node;
                    parent_node->right              = grand_parent_node;
                    parent_node->color              = NODE_BLACK;
                    grand_parent_node->color        = NODE_RED;
                } else if (node_is_left) {
                    // Right-Left rotation
                    grand_parent_node->parent->right = node;
                    node->parent                     = grand_parent_node->parent;
                    parent_node->left                = NULL;
                    node->right                      = parent_node;
                    node->left                       = grand_parent_node;
                    grand_parent_node->parent        = node;
                    node->color                      = NODE_BLACK;
                    grand_parent_node->color         = NODE_RED;
                } else if (parent_node_is_left) {
                    // left-Right rotation
                    grand_parent_node->parent->left = node;
                    node->parent                    = grand_parent_node->parent;
                    parent_node->right              = NULL;
                    node->right                     = grand_parent_node;
                    node->left                      = parent_node;
                    grand_parent_node->parent       = node;
                    node->color                     = NODE_BLACK;
                    grand_parent_node->color        = NODE_RED;
                } else {
                    // Left rotation
                    parent_node->parent              = grand_parent_node->parent;
                    grand_parent_node->parent->right = parent_node;
                    grand_parent_node->right         = parent_node->left;
                    grand_parent_node->parent        = parent_node;
                    parent_node->left                = grand_parent_node;
                    parent_node->color               = NODE_BLACK;
                    grand_parent_node->color         = NODE_RED;
                }
                break;
            }
        }
    }
}

Rb_Node* rb_node_new(uint32_t root_val, bool is_root) {
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


void rb_node_insert(Rb_Node* root, uint32_t val) {
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