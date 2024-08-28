#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* root = NULL;
struct Node* top = NULL;
struct Node* temp = NULL;

struct Node* createNode(int n){
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
    new->data = n;
    new->next = NULL;
    return new;
}

void push(int n){
    struct Node* newElement = NULL;
    newElement = createNode(n);
    if(root == NULL && top == NULL){
        root = newElement;
        top = newElement;
    }
    else{
        top->next = newElement;
        top = top->next;
    }
}

void pop(){
    if(top == NULL){
        printf("STACK IS EMPTY!!!");
    }
    else if (root == top) {  // Only one element in the stack
        free(top);
        root = NULL;
        top = NULL;
    } 
    else {
        temp = root;
        while (temp->next != top) {
            temp = temp->next;
        }
        free(top);
        top = temp;
        top->next = NULL;
    }
}

void display(){
    temp = root;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    // Your code goes here
    // push(5);
    // push(4);
    // push(3);
    // push(2);
    // push(1);
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();
    // display();
    
    return 0;
}