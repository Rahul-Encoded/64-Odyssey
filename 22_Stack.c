#include <stdio.h>
#include <stdlib.h>

/*
1. Peek
2. Push()
3. Pop()
4. Traverse()
5. isEmpty()
6. isFull
7. size()
*/

void push(int element, int* top, int* capacity, int** stack);
int isFull(int top, int capacity);
void pop(int* top, int* stack);
int isEmpty(int top);
int peek(int* stack, int top);
void traverse(int* stack, int top);

int main() {
    int capacity;
    printf("Allot initial memory to your stack: ");
    scanf("%d", &capacity);

    int* stack;
    int top = -1;
    stack = (int*)calloc(capacity, sizeof(int));

    // printf("Create your stack:\n");
    // for (int i = 0; i < capacity; i++) {
    //     printf("Element no. %d: ", i);
    //     scanf("%d", &stack[i]);
    //     top++;
    // }

    int element;
    printf("Which operations do you wish to perform on stack:\n1. Peek\n2. Push()\n3. Pop()\n4. Traverse()\n5. isEmpty()\n6. isFull()\n7. size()\n8. END\n");

    int operation;

    while (1) {
        printf("\n");
        scanf("%d", &operation);
        switch (operation) {
        case 1:
            peek(stack, top);
            break;

        case 2:
            printf("\nEnter the element you wish to push: ");
            scanf("%d", &element);
            push(element, &top, &capacity, &stack);
            break;

        case 3:
            pop(&top, stack);
            break;

        case 4:
            traverse(stack, top);
            break;

        case 5:
            printf("Stack is %sempty!\n", isEmpty(top) ? "" : "NOT ");
            break;

        case 6:
            printf("Stack is %sfull\n", isFull(top, capacity) ? "" : "NOT ");
            break;

        case 7:
            printf("No. of elements stack can hold is %d\n", capacity);
            break;

        case 8:
            exit(0);

        default:
            printf("Enter a valid option\n");
        }

        printf("Which operations do you wish to perform on stack:\n1. Peek\n2. Push()\n3. Pop()\n4. Traverse()\n5. isEmpty()\n6. isFull()\n7. size()\n8. END\n");
    }

    return 0;
}

void push(int element, int* top, int* capacity, int** stack) {
    if (isFull(*top, *capacity)) {
        printf("STACK IS FULL!!!\n");
        printf("Do you still wish to push? [Y/N]: ");
        char addMem;
        scanf(" %c", &addMem); // Note space before %c to consume any leftover newline character
        switch (addMem) {
        case 'Y':
        case 'y':
            *capacity += 1;
            *stack = (int*)realloc(*stack, (*capacity) * sizeof(int));
            (*top)++;
            (*stack)[*top] = element;
            printf("%d inserted\n", element);
            break;

        case 'N':
        case 'n':
            printf("You have decided not to push anymore!\n");
            break;

        default:
            printf("Invalid input! You have decided not to push anymore!\n");
            break;
        }
    } 
    else{
        (*top)++;
        (*stack)[*top] = element;
        printf("%d inserted\n", element);
    }
}

int isFull(int top, int capacity){
    if(top == capacity - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void pop(int* top, int* stack) {
    if (isEmpty(*top)) {
        printf("STACK IS EMPTY!!!\n");
    } 
    else{
        printf("%d popped\n", stack[*top]);
        (*top)--;
    }
}

int isEmpty(int top){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}


int peek(int* stack, int top) {
    if (isEmpty(top)) {
        printf("STACK IS EMPTY!!!\n");
    } 
    else{
        printf("Top = %d", stack[top]);
    }
}

void traverse(int* stack, int top) {
    if (isEmpty(top)) {
        printf("STACK IS EMPTY!!!\n");
    } 
    else{
        printf("Elements of Stack:\n");
        for (int i = 0; i <= top; i++) {
            printf("%d\n", stack[i]);
        }
        printf("\n");
    }
}
