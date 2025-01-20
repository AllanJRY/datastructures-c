#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @struct Singly_Linked_List_Node
 * @brief Represents a node in a singly linked list.
 *
 * This structure is used to create and manage a singly linked list, where each
 * node contains a value (`val`) and a pointer (`next`) to the next node in the list.
 *
 * A singly linked list is a linear data structure where each element (node) points
 * to the next one in the sequence. The last node in the list points to `NULL` to
 * indicate the end of the list.
 *
 * Fields:
 * - `val`:
 *   The integer value stored in the node. This can be any value the list is meant
 *   to manage or represent.
 *
 * - `next`:
 *   A pointer to the next node in the list. If the current node is the last node,
 *   `next` is set to `NULL`.
 *
 * Example:
 * 
 * ```c
 * // Create nodes
 * Singly_Linked_List_Node node1 = {10, NULL};
 * Singly_Linked_List_Node node2 = {20, NULL};
 * Singly_Linked_List_Node node3 = {30, NULL};
 * 
 * // Link nodes to form a list
 * node1.next = &node2;
 * node2.next = &node3;
 * 
 * // Iterate through the list
 * Singly_Linked_List_Node* current = &node1;
 * while (current != NULL) {
 *     printf("%d -> ", current->val);
 *     current = current->next;
 * }
 * printf("NULL\n");
 * ```
 *
 * Output:
 * ```
 * 10 -> 20 -> 30 -> NULL
 * ```
 *
 * Notes:
 * - The list can grow dynamically by allocating new nodes and linking them.
 * - Operations such as insertion, deletion, and traversal can be implemented
 *   based on this structure.
 */
typedef struct Singly_Linked_List_Node {
    int val;
    struct Singly_Linked_List_Node* next;
} Singly_Linked_List_Node;

Singly_Linked_List_Node* singly_linked_list_new(int head_val);

size_t singly_linked_list_len(Singly_Linked_List_Node* linked_list_head);

void singly_linked_list_print(Singly_Linked_List_Node* linked_list_head);

void singly_linked_list_append(Singly_Linked_List_Node* linked_list_head, int val);

void singly_linked_list_insert(Singly_Linked_List_Node* linked_list_head, size_t idx, int val);

bool singly_linked_list_remove(Singly_Linked_List_Node* linked_list_head, size_t idx, int* removed_val);

bool singly_linked_list_lookup(Singly_Linked_List_Node* linked_list_head, int needle_val, size_t* found_idx);

void singly_linked_list_free(Singly_Linked_List_Node* linked_list_head);

#endif