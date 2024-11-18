#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node *next;
};

void insertAtBeg(struct node **head, int val) {
    struct node *temp = malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("No Memory Available\n");
        return;
    }
    temp->val = val;
    temp->next = *head;
    *head = temp;
}

void insertAtEnd(struct node **head, int val) {
    struct node *temp = malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("No Memory Available\n");
        return;
    }
    if(*head == NULL) {
        temp->val = val;
        temp->next = NULL;
        *head = temp;
        return;
    }
    struct node *ptr = *head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    temp->val = val;
    temp->next = NULL;
    ptr->next = temp;
}

void insertAtPos(struct node **head, int pos, int val) {
    struct node *temp = malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("No Memory Available\n");
        return;
    }
    struct node *ptr = *head;
    if(*head == NULL) {
        temp->val = val;
        temp->next = NULL;
        *head = temp;
        return;
    }
    for(int i=0; i<pos-1 && ptr->next != NULL; i++) {
        ptr = ptr->next;
    }
    if(ptr == NULL) {
        printf("Invalid Position");
        free(temp);
        return;
    }
    temp->val = val;
    temp->next = ptr->next;
    ptr->next = temp;
}

void deleteFirst(struct node **head) {
    if(*head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(struct node **head) {
    if(*head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct node *ptr = *head;
    if(ptr->next == NULL) {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    while(ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    struct node *temp = ptr->next;
    ptr->next = NULL;
    free(temp);
}

void deleteAtPos(struct node **head, int pos) {
    if(*head == NULL) {
        printf("List is Empty\n");
        return;
    }
    if(pos == 0) {
        deleteFirst(head);
        return;
    }
    struct node *ptr = *head;
    for(int i=0; i<pos-1 && ptr->next != NULL; i++) {
        ptr = ptr->next;
    }
    if(ptr->next == NULL) {
        printf("Invalid Position");
    }
    if(ptr->next->next != NULL) {
        struct node *temp = ptr->next;
        ptr->next = ptr->next->next;
        free(temp);
    }
    else{
        struct node *temp = ptr->next;
        ptr->next = ptr->next->next;
        free(temp);
    }
}

void display(struct node *head) {
    struct node *temp = head;
    if(temp == NULL) {
        printf("List is Empty\n");
        return;
    }
    while(temp != NULL) {
        printf("%d->", temp->val);
        temp = temp->next;
    }
    printf("Null\n");
}

int main() {
    int val;
    int pos;
    struct node *head = NULL;
    printf("Enter number corresponding to their operation\n");
    printf("1. Insert a node at the beginning\n");
    printf("2. Insert a node at the end\n");
    printf("3. Insert a node at a given position where position is entered by the user.\n");
    printf("4. Delete a node from the beginning\n");
    printf("5. Delete a node from the end\n");
    printf("6. Delete a node from a given position where position is entered by the user.\n");
    printf("7. Display the list.\n");
    printf("8. Exit\n");
    int opr;
    while(1) {
        printf("Enter operation number: ");
        scanf("%d", &opr);
        switch(opr) {
            case(1):
                printf("Enter value to be inserted: ");
                scanf("%d", &val);
                insertAtBeg(&head, val);
                break;
            case(2):
                printf("Enter value to be inserted: ");
                scanf("%d", &val);
                insertAtEnd(&head, val);
                break;
            case(3):
                printf("Enter position at which value will be inserted: ");
                scanf("%d", &pos);
                printf("Enter value to be inserted: ");
                scanf("%d", &val);
                insertAtPos(&head, pos, val);
                break;
            case(4):
                deleteFirst(&head);
                break;
            case(5):
                deleteLast(&head);
                break;
            case(6):
                printf("Enter position at which value will be deleted: ");
                scanf("%d", &pos);
                deleteAtPos(&head, pos);
                break;
            case(7):
                display(head);
                break;
            case(8):
                exit(0);
        }
    }
    return 0;
}