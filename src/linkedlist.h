#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

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