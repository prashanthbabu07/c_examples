/* create doubly linked list */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

void insert_node(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void print_list(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void remove_node(node **head, int data) {
    node *temp = *head;
    if (temp->data == data) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        if (temp->next->data == data) {
            node *temp2 = temp->next;
            temp->next = temp->next->next;
            if (temp->next != NULL) {
                temp->next->prev = temp;
            }
            free(temp2);
            return;
        }
        temp = temp->next;
    }
}
