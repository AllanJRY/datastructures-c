#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "red_black_tree.h"

void i32_rb_tree_init(I32_Bb_Tree* tree, size_t initial_cap) {
    tree->nodes = (I32_Rb_Tree_Node*) malloc(sizeof(I32_Rb_Tree_Node) * initial_cap);
    if (tree->nodes == NULL) {
        printf("Unable to allocate memory for the RB tree backing array.");
        exit(1);
    }

    memset(tree->nodes, 0, sizeof(I32_Rb_Tree_Node) * initial_cap);
    tree->len = 0;
    tree->cap = initial_cap;
}

void i32_rb_tree_free(I32_Bb_Tree* tree) {
    free(tree->nodes);
    tree->len = 0;
    tree->cap = 0;
}

void i32_rb_tree_insert(I32_Bb_Tree* tree, int value) {
    // todo
}