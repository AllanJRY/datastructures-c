#include "linkedlist.h"

Singly_Linked_List_Node* singly_linked_list_new(int head_val) {
    Singly_Linked_List_Node* linked_list_head = (Singly_Linked_List_Node*) malloc(sizeof(Singly_Linked_List_Node));
    linked_list_head->val              = head_val;
    linked_list_head->next             = NULL;
    return linked_list_head;
}

size_t singly_linked_list_len(Singly_Linked_List_Node* linked_list_head) {
    assert(linked_list_head != NULL && "Linked List head is NULL.");

    size_t len = 1;
    Singly_Linked_List_Node* curr_node = linked_list_head;
    for (;curr_node->next != NULL;) {
        len += 1;
        curr_node = curr_node->next;
    }

    return len;
}

void singly_linked_list_print(Singly_Linked_List_Node* linked_list_head) {
    Singly_Linked_List_Node* curr_node = linked_list_head;
    for (;curr_node != NULL;) {
        if (curr_node != linked_list_head) {
            printf(" -> %d", curr_node->val);
        } else {
            printf(" %d", curr_node->val);
        }

        curr_node = curr_node->next;
    }
}

void singly_linked_list_append(Singly_Linked_List_Node* linked_list_head, int val) {
    assert(linked_list_head != NULL && "Linked List head is NULL.");

    if (linked_list_head->next == NULL) {
        Singly_Linked_List_Node* new_node = (Singly_Linked_List_Node*) malloc(sizeof(Singly_Linked_List_Node));
        new_node->val              = val;
        new_node->next             = NULL;
        linked_list_head->next     = new_node;
        return;
    }

    Singly_Linked_List_Node* last_node = linked_list_head->next;
    for (;last_node->next != NULL;) {
        last_node = last_node->next;
    }

    if (last_node->next == NULL) {
        Singly_Linked_List_Node* new_node = (Singly_Linked_List_Node*) malloc(sizeof(Singly_Linked_List_Node));
        new_node->val              = val;
        new_node->next             = NULL;
        last_node->next            = new_node;
        return;
    }
}

void singly_linked_list_insert(Singly_Linked_List_Node* linked_list_head, size_t idx, int val) {
    assert(linked_list_head != NULL && "Linked List head is NULL.");

    if (idx == 0) {
        Singly_Linked_List_Node* prev_head_node = (Singly_Linked_List_Node*) malloc(sizeof(Singly_Linked_List_Node));
        assert(prev_head_node != NULL && "Unable to allocate more memory.");
        prev_head_node->val  = linked_list_head->val;
        prev_head_node->next = linked_list_head->next;

        linked_list_head->val  = val;
        linked_list_head->next = prev_head_node;
        return;
    }

    size_t i = 1;
    Singly_Linked_List_Node* prev_node = linked_list_head;
    Singly_Linked_List_Node* curr_node = linked_list_head->next;
    for(;i <= idx;) {
        if (prev_node == NULL) {
            return;
        }

        if (i == idx) {
            Singly_Linked_List_Node* new_node = (Singly_Linked_List_Node*) malloc(sizeof(Singly_Linked_List_Node));
            assert(new_node != NULL && "Unable to allocate more memory.");
            new_node->val              = val;
            new_node->next             = NULL;
            prev_node->next            = new_node;

            if(curr_node != NULL) {
                new_node->next = curr_node;
            }
            return;
        }

        i += 1;
        prev_node = curr_node;
        if (curr_node != NULL) {
            curr_node = curr_node->next;
        }
    }
}

bool singly_linked_list_remove(Singly_Linked_List_Node* linked_list_head, size_t idx, int* removed_val) {
    assert(linked_list_head != NULL && "Linked List head is NULL.");

    if (idx == 0) {
        *removed_val = linked_list_head->val;
        if (linked_list_head->next != NULL) {
            Singly_Linked_List_Node* to_free = linked_list_head->next;
            linked_list_head->val  = to_free->val;
            linked_list_head->next = to_free->next;
            free(to_free);
            return true;
        } else {
            free(linked_list_head);
        }
    }

    size_t i = 1;
    Singly_Linked_List_Node* prev_node = linked_list_head;
    Singly_Linked_List_Node* curr_node = linked_list_head->next;
    for(;i <= idx;) {
        if (prev_node == NULL || (i == idx && curr_node == NULL)) {
            return false;
        }

        if (i == idx) {
            prev_node->next = curr_node->next;
            *removed_val = curr_node->val;
            free(curr_node);
            return true;
        }

        i += 1;
        prev_node = curr_node;
        if (curr_node != NULL) {
            curr_node = curr_node->next;
        }
    }

    return false;
}

bool singly_linked_list_lookup(Singly_Linked_List_Node* linked_list_head, int needle_val, size_t* found_idx) {
    assert(linked_list_head != NULL && "Linked List head is NULL.");

    size_t idx = 0;
    Singly_Linked_List_Node* curr_node = linked_list_head;
    for(;curr_node != NULL;) {
        if (curr_node->val == needle_val) {
            *found_idx = idx;
            return true;
        }

        curr_node = curr_node->next;
        idx += 1;
    }

    return false;
}

void singly_linked_list_free(Singly_Linked_List_Node* linked_list_head) {
    assert(linked_list_head != NULL && "Linked List head is NULL.");

    Singly_Linked_List_Node* to_free = linked_list_head;
    Singly_Linked_List_Node* next    = linked_list_head->next;
    free(to_free);

    for (;next->next != NULL;) {
        to_free = next;
        next = next->next;
        free(to_free);
    }
}
