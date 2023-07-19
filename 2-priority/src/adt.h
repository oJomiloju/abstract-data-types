
#ifndef ADT_H
#define ADT_H

// YOUR FUNCTION PROTOTYPES HERE
typedef struct node {
    char *data;
    int priority;
    struct node *next;
} Node;

typedef struct priority_queue {
    Node *head;
} PriorityQueue;
void printPriorityQueue(PriorityQueue *pq);
char *dequeue(PriorityQueue *pq);
void enqueue(PriorityQueue *pq, char *data, int priority);
PriorityQueue *createPriorityQueue();

#endif /* ADT_H */