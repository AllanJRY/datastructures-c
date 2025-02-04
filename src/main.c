#include "tree/red_black_tree.h"

int main(void) {
    // demo_singly_linked_list();
    // demo_doubly_linked_list();

    I32_Rb_Node* tree_root = i32_rb_node_new(1);
    i32_rb_node_free(tree_root);

    return 0;
}