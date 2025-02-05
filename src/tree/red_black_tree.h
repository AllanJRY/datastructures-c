#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdbool.h>
#include <stdint.h>

typedef uint8_t Rb_Node_Color;

#define NODE_BLACK 0
#define NODE_RED   1

// TODO: Add an implementation variation backed by arrays instead of allocating nodes.

typedef struct Rb_Node {
    struct Rb_Node* parent;
    struct Rb_Node* left;
    struct Rb_Node* right;
    uint32_t        val;
    Rb_Node_Color   color;
} Rb_Node;

Rb_Node* rb_node_new(int root_val, bool is_root);
void rb_node_free(Rb_Node* root);
void rb_node_insert(Rb_Node* root, int value);

#endif  // RED_BLACK_TREE_H
