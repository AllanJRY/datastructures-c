#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdint.h>

#define NODE_BLACK 0
#define NODE_RED   1

// TODO: Change the implementation to be backed by arrays instead of allocating nodes on the fly.

typedef struct I32_Bb_Tree {
    size_t            len;
    size_t            cap;
    I32_Rb_Tree_Node* nodes;
} I32_Bb_Tree;

typedef struct I32_Rb_Tree_Node {
    size_t   left;
    size_t   right;
    uint32_t val;
    uint8_t  color;
} I32_Rb_Tree_Node;

void i32_rb_tree_init(I32_Bb_Tree* tree,int root_val);
void i32_rb_tree_free(I32_Bb_Tree* tree);
void i32_rb_tree_insert(I32_Bb_Tree* tree, int value);

#endif  // RED_BLACK_TREE_H
