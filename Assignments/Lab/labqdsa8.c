
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;

    struct node *next;
};

void insert_at_first(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    
    if (*head == NULL) { 
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        struct node* last = (*head)->prev;

        newNode->next = *head;
        newNode->prev = last;
        (*head)->prev = newNode;
        last->next = newNode;

        *head = newNode; 
    }
}


void insert_at_end(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        struct node* last = (*head)->prev;

        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

void insert_at_position(struct node** head, int data, int position) {
    if (position == 0) {
        insert_at_first(head, data);
        return;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    struct node* temp = *head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
        if (temp == *head) {
            printf("Invalid Position\n");
            return;
        }
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}


void delete_first(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* last = (*head)->prev;
    struct node* temp = *head;

    if (*head == (*head)->next) { 
        *head = NULL;
    } else {
        *head = temp->next;
        (*head)->prev = last;
        last->next = *head;
    }
    free(temp);
}

void delete_last(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* last = (*head)->prev;

    if (*head == last) { 
        free(*head);
        *head = NULL;
    } else {
        struct node* second_last = last->prev;
        second_last->next = *head;
        (*head)->prev = second_last;
        free(last);
    }
}
void delete_at_position(struct node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 0) {
        delete_first(head);
        return;
    }

    struct node* temp = *head;

    for (int i = 0; i < position; i++) {
        temp = temp->next;
        if (temp == *head) {
            printf("Invalid position\n");
            return;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int choice, data, position;
    int flag = 1;

    printf("Menu:\n");
    printf("Enter 1 to Insert a node at the front of the linked list\n");
    printf("Enter 2 to Insert a node at the end of the linked list\n");
    printf("Enter 3 to Insert a node at the given position\n");
    printf("Enter 4 to Delete the first node\n");
    printf("Enter 5 to Delete the last node\n");
    printf("Enter 6 to Delete a node at the given position\n");
    printf("Enter 7 to Display the elements of the linked list\n");
    printf("Enter 8 to end the program\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insert_at_first(&head, data);
                break;

            case 2:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;

            case 3:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position at which it is to be inserted: ");
                scanf("%d", &position);
                insert_at_position(&head, data, position);
                break;

            case 4:
                delete_first(&head);
                break;

            case 5:
                delete_last(&head);
                break;

            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                delete_at_position(&head, position);
                break;

            case 7:
                display(head);
                break;

            case 8:
                flag = 0;
                break;

            default:
                printf("Invalid Choice.\n");
                break;
        }
    } while (flag != 0);

    return 0;
}