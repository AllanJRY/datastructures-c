#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Linked_List_Node {
    int val;
    struct Linked_List_Node* next;
} Linked_List_Node;

Linked_List_Node* linked_list_new(int head_val) {
    Linked_List_Node* linked_list_head = (Linked_List_Node*) malloc(sizeof(Linked_List_Node));
    linked_list_head->val              = head_val;
    linked_list_head->next             = NULL;
    return linked_list_head;
}

void linked_list_append(Linked_List_Node* linked_list_head, int val) {
    assert(linked_list_head != NULL && "Linked List head is NULL.");

    if (linked_list_head->next == NULL) {
        Linked_List_Node* new_node = (Linked_List_Node*) malloc(sizeof(Linked_List_Node));
        new_node->val              = val;
        new_node->next             = NULL;
        linked_list_head->next     = new_node;
        return;
    }

    Linked_List_Node* last_node = linked_list_head->next;
    for (;last_node->next != NULL;) {
        last_node = last_node->next;
    }

    if (last_node->next == NULL) {
        Linked_List_Node* new_node = (Linked_List_Node*) malloc(sizeof(Linked_List_Node));
        new_node->val              = val;
        new_node->next             = NULL;
        last_node->next            = new_node;
        return;
    }
}

void linked_list_free(Linked_List_Node* linked_list_head) {
    assert(linked_list_head != NULL && "Linked List head is NULL.");

    Linked_List_Node* to_free = linked_list_head;
    Linked_List_Node* next    = linked_list_head->next;
    free(to_free);

    for (;next->next != NULL;) {
        to_free = next;
        next = next->next;
        free(to_free);
    }
}

int main(void) {
    Linked_List_Node* linked_list_head = linked_list_new(1);

    linked_list_append(linked_list_head, 2);
    linked_list_append(linked_list_head, 3);
    linked_list_append(linked_list_head, 4);

    printf("\nSingly Linked list:");
    Linked_List_Node* curr_node = linked_list_head;
    for (;curr_node != NULL;) {
        if (curr_node != linked_list_head) {
            printf(" - %d", curr_node->val);
        } else {
            printf(" %d", curr_node->val);
        }

        curr_node = curr_node->next;
    }
    printf("\n");

    linked_list_free(linked_list_head);

    return 0;
}