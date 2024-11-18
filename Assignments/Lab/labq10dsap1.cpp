#include <iostream>
using namespace std;

int queue[5];
int front = -1, rear = -1;

void enqueue(int value) {
    if (front == (rear + 1) % 5) {
        cout << "Queue is Full" << endl;
        return;
    }
    if(front == -1 && rear == -1)
        front = rear = 0;
    else if((rear == 4) && (front != 0))
        rear = 0;
    else
        rear++;
    queue[rear] = value;
    cout << value << " inserted into the queue" << endl;
}

void dequeue() {
    if (front == -1) {
        cout << "Queue is Empty" << endl;
        return;
    }

    cout << queue[front] << " deleted from the queue" << endl;

    if (front == rear) {
        front = rear = -1;
    } else if (front == 4) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is Empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
    } else {
        for (int i = front; i < 5; i++) {
            cout << queue[i] << " ";
        }
        for (int i = 0; i <= rear; i++) {
            cout << queue[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    enqueue(40);
    enqueue(50);
    display();
    enqueue(60);
    display();
    return 0;
}