// II.	Write a program to implement QUEUE using Linked List that performs following operations
// (h)	INSERT 
// (i)	DELETE 
// (j)	DISPLAY
#include <stdio.h>
#include <stdlib.h>

// node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

// queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// function to initialize the queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// function to insert an element into the queue
void insert(struct Queue* queue, int value) {
    struct Node* newNode = createNode(value);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// function to delete an element from the queue
int delet(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1; // indicate empty queue
    }
    struct Node* temp = queue->front;
    int deletedValue = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL; // iif the queue is empty after deletion
    }
    free(temp);
    return deletedValue;
}

// function to display the queue
void display(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = queue->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// main function to demonstrate the queue operations
int main() {
    struct Queue* queue = createQueue();
    int choice, value;

    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(queue, value);
                break;
            case 2:
                value = delet(queue);
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exiting...\n");
                free(queue);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
