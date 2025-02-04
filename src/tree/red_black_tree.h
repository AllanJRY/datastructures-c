#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdint.h>

#define NODE_BLACK 0
#define NODE_RED   1

// TODO: Add an implementation variation backed by arrays instead of allocating nodes.

typedef struct I32_Rb_Node {
    struct I32_Rb_Node* parent;
    struct I32_Rb_Node* left;
    struct I32_Rb_Node* right;
    uint32_t            val;
    uint8_t             color;
} I32_Rb_Node;

I32_Rb_Node* i32_rb_node_new(int root_val);
void i32_rb_node_free(I32_Rb_Node* root);
void i32_rb_node_insert(I32_Rb_Node* root, int value);

#endif  // RED_BLACK_TREE_H
