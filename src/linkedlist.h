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
Singly_Linked_List_Node* singly_linked_list_new(int head_val);

/**
 * @brief Computes the length of a singly linked list.
 *
 * This function iterates through a singly linked list starting from the head node
 * and calculates the number of nodes in the list. The function assumes that the
 * linked list is properly terminated (i.e., the last node has its `next` pointer set to `NULL`).
 *
 * @param linked_list_head
 *        A pointer to the head node of the singly linked list.
 *        Must not be `NULL`. The function asserts this condition.
 *
 * @return 
 *        The total number of nodes in the linked list, including the head node.
 *
 * Example:
 *
 * ```c
 * // Create a linked list with three nodes
 * Singly_Linked_List_Node* head = singly_linked_list_new(10);
 * head->next = singly_linked_list_new(20);
 * head->next->next = singly_linked_list_new(30);
 *
 * // Compute the length of the list
 * size_t len = singly_linked_list_len(head);
 * printf("Linked List Length: %zu\n", len); // Output: Linked List Length: 3
 *
 * // Free the allocated memory
 * singly_linked_list_free(head);
 * ```
 *
 * Notes:
 * - The function requires the head pointer to be non-`NULL`. An assertion will fail
 *   if the head pointer is `NULL`.
 * - This function does not modify the linked list. It only traverses the list
 *   to count the nodes.
 *
 * Potential Errors:
 * - If the linked list has a cycle, this function will enter an infinite loop.
 *   Ensure the list is properly terminated.
 */
size_t singly_linked_list_len(Singly_Linked_List_Node* linked_list_head);

/**
 * @brief Prints the elements of a singly linked list to the standard output.
 *
 * This function traverses a singly linked list starting from the head node and 
 * prints the value of each node in the order they appear in the list. Each node's 
 * value is separated by a " -> " delimiter, starting with the head node's value.
 *
 * @param linked_list_head
 *        A pointer to the head node of the singly linked list.
 *        If the head is `NULL`, the function will silently print nothing.
 *
 * Example:
 *
 * ```c
 * // Create a linked list with three nodes
 * Singly_Linked_List_Node* head = singly_linked_list_new(10);
 * head->next = singly_linked_list_new(20);
 * head->next->next = singly_linked_list_new(30);
 *
 * // Print the linked list
 * singly_linked_list_print(head);
 * // Output: 10 - 20 - 30
 *
 * // Free the allocated memory
 * singly_linked_list_free(head);
 * ```
 *
 * Notes:
 * - The function handles lists with a single node gracefully by printing only
 *   the value of that node without the delimiter.
 * - If the list is empty (`linked_list_head` is `NULL`), the function does not
 *   output anything.
 * - This function does not modify the linked list; it only traverses and prints
 *   the node values.
 *
 * Potential Errors:
 * - Ensure the list is properly terminated. If the list contains a cycle, this
 *   function will enter an infinite loop.
 */
void singly_linked_list_print(Singly_Linked_List_Node* linked_list_head);

/**
 * @brief Appends a new node with a given value to the end of a singly linked list.
 *
 * This function traverses the given singly linked list starting from the head node, 
 * locates the last node in the list, and appends a new node containing the specified value.
 *
 * @param linked_list_head
 *        A pointer to the head node of the singly linked list.
 *        Must not be `NULL`. The function will assert and terminate execution
 *        if a `NULL` head is provided.
 *
 * @param val
 *        The integer value to store in the new node appended to the list.
 *
 * Example:
 *
 * ```c
 * // Create a linked list with one node
 * Singly_Linked_List_Node* head = singly_linked_list_new(10);
 *
 * // Append values to the list
 * singly_linked_list_append(head, 20);
 * singly_linked_list_append(head, 30);
 *
 * // Print the linked list
 * singly_linked_list_print(head); // Output: 10 -> 20 -> 30
 *
 * // Free the allocated memory
 * singly_linked_list_free(head);
 * ```
 *
 * Notes:
 * - If the list has only the head node (`linked_list_head->next` is `NULL`), 
 *   the function directly appends the new node as the second node in the list.
 * - The function uses a loop to traverse to the last node for larger lists, ensuring
 *   that the new node is appended correctly.
 * - Memory for the new node is dynamically allocated using `malloc`. The user
 *   is responsible for freeing this memory when the linked list is no longer needed or use
 *   `singly_linked_list_free` procedure.
 *
 * Potential Errors:
 * - The function asserts that `linked_list_head` is not `NULL`. Ensure that the list
 *   has been properly initialized before calling this function.
 * - This function assumes a well-formed linked list. If the list contains a cycle,
 *   the function will enter an infinite loop.
 * - If memory allocation using `malloc` fails, the behavior is undefined. Ensure
 *   sufficient memory is available before calling this function.
 *
 * Performance:
 * - Time complexity: O(n), where `n` is the number of nodes in the list. The function
 *   must traverse the list to locate the last node.
 * - Space complexity: O(1) for auxiliary operations. The new node requires additional memory.
 */
void singly_linked_list_append(Singly_Linked_List_Node* linked_list_head, int val);

/**
 * @brief Inserts a new node with a specified value at a given index in a singly linked list.
 *
 * This function allows inserting a node at any valid index in the singly linked list. 
 * If the index is `0`, the function inserts the new value at the head of the list by 
 * adjusting the head node. For indices greater than `0`, the function traverses the 
 * list to the specified position and inserts the new node.
 *
 * @param linked_list_head
 *        A pointer to the head node of the singly linked list.
 *        Must not be `NULL`. The function will assert and terminate execution
 *        if a `NULL` head is provided.
 *
 * @param idx
 *        The zero-based index at which to insert the new node.
 *        - If `idx == 0`, the new value becomes the new head of the list.
 *        - If `idx` is greater than the length of the list, the function does nothing.
 *
 * @param val
 *        The integer value to store in the new node.
 *
 * Example:
 *
 * ```c
 * // Create a linked list with one node
 * Singly_Linked_List_Node* head = singly_linked_list_new(10);
 *
 * // Append values to the list
 * singly_linked_list_append(head, 20);
 * singly_linked_list_append(head, 30);
 *
 * // Insert value at index 1
 * singly_linked_list_insert(head, 1, 15);
 *
 * // Print the linked list
 * singly_linked_list_print(head); // Output: 10 -> 15 -> 20 -> 30
 *
 * // Free the allocated memory
 * singly_linked_list_free(head);
 * ```
 *
 * Notes:
 * - If the list is empty (head is `NULL`), the function will assert. Always initialize 
 *   the list before calling this function.
 * - If the index is greater than the current length of the list, the function does nothing.
 * - If the index is `0`, the function replaces the head's value and adjusts the 
 *   structure by creating a new node to hold the previous head's data.
 * - Memory for the new node is dynamically allocated using `malloc`. The user is 
 *   responsible for freeing this memory when the linked list is no longer needed.
 *
 * Potential Errors:
 * - The function asserts that `linked_list_head` is not `NULL`.
 * - Memory allocation failure will cause an assertion error if `malloc` returns `NULL`.
 * - The function assumes a well-formed linked list. Undefined behavior may occur if the
 *   list contains cycles.
 *
 * Performance:
 * - Time complexity: O(n), where `n` is the length of the list up to the specified index.
 * - Space complexity: O(1) for auxiliary operations. The new node requires additional memory.
 */
void singly_linked_list_insert(Singly_Linked_List_Node* linked_list_head, size_t idx, int val);

/**
 * @brief Removes a node at a specified index from a singly linked list and optionally retrieves its value.
 *
 * This function removes a node at a given zero-based index in the singly linked list. 
 * If the removal is successful, the value of the removed node is stored in the provided 
 * pointer `removed_val`, and the function returns `true`. If the index is invalid or out of 
 * range, the function returns `false` without modifying the list.
 *
 * @param linked_list_head
 *        A pointer to the head node of the singly linked list.
 *        Must not be `NULL`. The function asserts and terminates execution if the head is `NULL`.
 *
 * @param idx
 *        The zero-based index of the node to remove.
 *        - If `idx == 0`, the head node is removed. If there are subsequent nodes, the head 
 *          pointer is adjusted to the next node.
 *        - If `idx` is out of range (greater than the list length), the function returns `false`.
 *
 * @param removed_val
 *        A pointer to an integer where the value of the removed node will be stored.
 *        If `NULL`, the value of the removed node is not stored, but the removal is still performed.
 *
 * @return 
 *        `true` if the node is successfully removed, `false` otherwise.
 *
 * Example:
 *
 * ```c
 * // Create a linked list with multiple nodes
 * Singly_Linked_List_Node* head = singly_linked_list_new(10);
 * singly_linked_list_append(head, 20);
 * singly_linked_list_append(head, 30);
 *
 * int removed_val;
 *
 * // Remove the second node (index 1)
 * if (singly_linked_list_remove(head, 1, &removed_val)) {
 *     printf("Removed value: %d\n", removed_val); // Output: Removed value: 20
 * }
 *
 * // Print the modified linked list
 * singly_linked_list_print(head); // Output: 10 -> 30
 *
 * // Free the list
 * singly_linked_list_free(head);
 * ```
 *
 * Notes:
 * - If the index is `0`, the head node is removed, and the head pointer is adjusted.
 * - If the index is greater than the list's length, the function returns `false`.
 * - If `removed_val` is `NULL`, the value of the removed node is not captured.
 * - Memory for the removed node is freed using `free`.
 * - The user is responsible for ensuring the list is well-formed and contains no cycles.
 *
 * Potential Errors:
 * - The function asserts if the `linked_list_head` is `NULL`.
 * - The function assumes valid memory allocation and will not handle memory-related errors.
 * - Passing `NULL` as `removed_val` will omit capturing the removed node's value but will not cause an error.
 *
 * Performance:
 * - Time complexity: O(n), where `n` is the index of the node to remove.
 * - Space complexity: O(1) for auxiliary operations. The function modifies the list in place.
 */
bool singly_linked_list_remove(Singly_Linked_List_Node* linked_list_head, size_t idx, int* removed_val);

/**
 * @brief Searches for a specific value in a singly linked list and retrieves its index if found.
 *
 * This function traverses a singly linked list starting from the head and searches for the first 
 * occurrence of a specified value (`needle_val`). If the value is found, its index is stored in 
 * the pointer `found_idx`, and the function returns `true`. If the value is not found, the function 
 * returns `false`.
 *
 * @param linked_list_head
 *        A pointer to the head node of the singly linked list.
 *        Must not be `NULL`. The function asserts and terminates execution if the head is `NULL`.
 *
 * @param needle_val
 *        The value to search for in the linked list.
 *
 * @param found_idx
 *        A pointer to a `size_t` variable where the index of the found value will be stored.
 *        If the value is not found, this pointer remains unchanged.
 *        Must not be `NULL`.
 *
 * @return 
 *        `true` if the value is found in the linked list, `false` otherwise.
 *
 * Example:
 *
 * ```c
 * // Create a linked list with multiple nodes
 * Singly_Linked_List_Node* head = singly_linked_list_new(10);
 * singly_linked_list_append(head, 20);
 * singly_linked_list_append(head, 30);
 *
 * size_t found_idx;
 *
 * // Search for a value in the list
 * if (singly_linked_list_lookup(head, 20, &found_idx)) {
 *     printf("Value found at index: %zu\n", found_idx); // Output: Value found at index: 1
 * } else {
 *     printf("Value not found.\n");
 * }
 *
 * // Free the list
 * singly_linked_list_free(head);
 * ```
 *
 * Notes:
 * - The function performs a linear search, visiting each node sequentially.
 * - If the list contains duplicate values, only the index of the first occurrence is returned.
 * - The user is responsible for ensuring the list is well-formed and contains no cycles.
 *
 * Potential Errors:
 * - The function asserts if `linked_list_head` or `found_idx` is `NULL`.
 * - If `needle_val` is not found, `found_idx` remains unchanged.
 *
 * Performance:
 * - Time complexity: O(n), where `n` is the number of nodes in the list.
 * - Space complexity: O(1) for auxiliary operations. The function modifies no external data other than `found_idx`.
 */
bool singly_linked_list_lookup(Singly_Linked_List_Node* linked_list_head, int needle_val, size_t* found_idx);

/**
 * @brief Frees all nodes of a singly linked list, starting from the head.
 *
 * This function iterates through the entire singly linked list starting from the given head node,
 * deallocates each node's memory using `free()`, and properly handles the deallocation of all linked list nodes.
 * After this function is called, the memory used by the linked list will be freed, and any access to the list
 * after this will result in undefined behavior.
 *
 * @param linked_list_head
 *        A pointer to the head node of the singly linked list.
 *        The head node is deallocated first, followed by each subsequent node.
 *        Must not be `NULL`. The function asserts and terminates execution if the head is `NULL`.
 *
 * Example:
 *
 * ```c
 * // Create a linked list with multiple nodes
 * Singly_Linked_List_Node* head = singly_linked_list_new(10);
 * singly_linked_list_append(head, 20);
 * singly_linked_list_append(head, 30);
 *
 * // Free all nodes in the linked list
 * singly_linked_list_free(head); // Frees the entire linked list
 * ```
 *
 * Notes:
 * - The function deallocates memory for each node in the list, including the head node.
 * - After calling this function, the linked list is no longer accessible, and any pointer to it should not be used.
 *
 * Potential Errors:
 * - The function asserts if the `linked_list_head` pointer is `NULL`.
 *
 * Performance:
 * - Time complexity: O(n), where `n` is the number of nodes in the linked list.
 * - Space complexity: O(1) since no additional space is used other than a couple of pointers for iteration.
 */
void singly_linked_list_free(Singly_Linked_List_Node* linked_list_head);

typedef struct Doubly_Linked_List_Node {
    int val;
    struct Doubly_Linked_List_Node* prev;
    struct Doubly_Linked_List_Node* next;
} Doubly_Linked_List_Node;

Doubly_Linked_List_Node* doubly_linked_list_new(int head_val);

void doubly_linked_list_free(Doubly_Linked_List_Node* linked_list_head);

size_t doubly_linked_list_len(Doubly_Linked_List_Node* linked_list_head);

void doubly_linked_list_print(Doubly_Linked_List_Node* linked_list_head);

void doubly_linked_list_print_backward(Doubly_Linked_List_Node* linked_list_head);

void doubly_linked_list_append(Doubly_Linked_List_Node* linked_list_head, int val);

void doubly_linked_list_prepend(Doubly_Linked_List_Node* linked_list_head, int val);

#endif