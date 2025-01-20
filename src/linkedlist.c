#include "linkedlist.h"

/**
 * @brief Creates a new singly linked list with a single node as the head.
 *
 * This function initializes a new singly linked list by allocating memory for the head node,
 * setting its value, and pointing its `next` pointer to `NULL` to indicate the end of the list.
 *
 * @param head_val
 *        The integer value to be stored in the head node of the list.
 *
 * @return 
 *        A pointer to the newly created head node of the linked list.
 *        Returns `NULL` if memory allocation fails.
 *
 * Example:
 *
 * ```c
 * // Create a new singly linked list with the head value of 10
 * Singly_Linked_List_Node* list_head = singly_linked_list_new(10);
 *
 * // Access the list
 * printf("Head Value: %d\n", list_head->val); // Output: Head Value: 10
 * printf("Next Node: %p\n", (void*)list_head->next); // Output: Next Node: (nil)
 *
 * // Free the allocated memory when done
 * free(list_head);
 * ```
 *
 * Notes:
 * - The caller is responsible for managing the memory allocated by this function.
 *   Ensure the memory is freed when the list is no longer needed.
 * - This function only creates a single-node list. To extend the list, additional
 *   nodes must be added manually by assigning values to the `next` pointer.
 *
 * Potential Errors:
 * - If `malloc` fails due to insufficient memory, the function will return `NULL`.
 */
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
            printf(" - %d", curr_node->val);
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
    assert(idx > 0 && "Cannot insert at index 0 with this procedure.");

    size_t i = 1;
    Singly_Linked_List_Node* prev_node = linked_list_head;
    Singly_Linked_List_Node* curr_node = linked_list_head->next;
    for(;i <= idx;) {
        if (prev_node == NULL) {
            return;
        }

        if (i == idx) {
            Singly_Linked_List_Node* new_node = (Singly_Linked_List_Node*) malloc(sizeof(Singly_Linked_List_Node));
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
    assert(idx > 0 && "Cannot delete at index 0 with this procedure.");

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
