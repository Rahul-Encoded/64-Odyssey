#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
struct Node* temp = NULL;

struct Node* createNode(int n){
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
    new->data = n;
    new->next = NULL;
    return new;
}

void enqueue(int n){
    struct Node* newElement = NULL;
    newElement = createNode(n);
    if(front == NULL && rear == NULL){
        front = newElement;
        rear = newElement;
    }
    else{
        rear->next = newElement;
        rear = rear->next;
    }
}

void *dequeue(){
    if(front == NULL){
        printf("QUEUE IS EMPTY!!!");
    }
    else{
        temp = front;
        front = front->next;
        temp->next = NULL;
        free(temp);
    }
}

void display(){
    temp = front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    // Your code goes here
    // enqueue(5);
    // enqueue(4);
    // enqueue(3);
    // enqueue(2);
    // enqueue(1);
    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    // display();
    
    return 0;
}