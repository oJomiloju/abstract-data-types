#include "adt.h"

// YOUR SOLUTION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


PriorityQueue *createPriorityQueue() {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->head = NULL;
    return pq;
}

void enqueue(PriorityQueue *pq, char *data, int priority) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (char*)malloc(strlen(data) + 1);
    strcpy(newNode->data, data);
    newNode->priority = priority;
    newNode->next = NULL;

    if (pq->head == NULL || priority < pq->head->priority) {
        newNode->next = pq->head;
        pq->head = newNode;
    } else {
        Node *current = pq->head;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

char *dequeue(PriorityQueue *pq) {
    if (pq->head == NULL) {
        return NULL;
    } else {
        Node *temp = pq->head;
        char *data = temp->data;
        pq->head = pq->head->next;
        free(temp);
        return data;
    }
}

void printPriorityQueue(PriorityQueue *pq) {
    Node *current = pq->head;
    while (current != NULL) {
        printf("Priority %d - %s\n",current->priority ,current->data);
        current = current->next;
    }
}

