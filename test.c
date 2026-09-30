#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the front of the list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // 1. Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // 2. Put the data into the node
    new_node->data = new_data;
    
    // 3. Link the old list to the next of the new node
    new_node->next = *head_ref;
    
    // 4. Move the head to point to the new node
    *head_ref = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Start with an empty list
    struct Node* head = NULL;

    // Insert elements
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Print the list: should display 30 -> 20 -> 10 -> NULL
    printf("Linked List: ");
    printList(head);

    return 0;
}