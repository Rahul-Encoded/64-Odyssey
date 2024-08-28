#include <stdio.h>
#include <stdlib.h>

int capacity;
int rear = 0;
int front = 0;

void enqueue(int** queue);
void dequeue(int** queue);
void firstElement(int** queue);
void display(int** queue);
void qSize(int** queue);

int main() {
    printf("\nEnter the capacity of your queue: ");
    scanf("%d", &capacity);
    int *queue;
    queue = (int*) calloc(capacity, sizeof(int));

    int ch;

    printf("\n 1 - Enqueue");
    printf("\n 2 - Dequeue");
    printf("\n 3 - Front element");
    printf("\n 4 - Display");
    printf("\n 5 - Queue size");
    printf("\n 6 - Exit");

    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue(&queue);
            break;

        case 2:
            dequeue(&queue);
            break;

        case 3:
            firstElement(&queue);
            break;

        case 4:
            display(&queue);
            break;

        case 5:
            qSize(&queue);
            break;

        case 6:
            free(queue);
            exit(0);
            break;

        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
    return 0;
}

void enqueue(int** queue) {
    int n;
    if (rear < capacity) {
        printf("Enter data : ");
        scanf("%d", &n);
        (*queue)[rear] = n;
        rear++;
    } else {
        printf("\nQueue is full. Do you wish to enqueue another element? [Y/N] ");
        char choice;
        scanf(" %c", &choice);  // Added a space before %c to consume any leftover newline
        if (choice == 'Y' || choice == 'y') {
            capacity++;
            *queue = (int*)realloc(*queue, capacity * sizeof(int));
            if (*queue == NULL) {
                perror("Realloc failed");
                exit(1);
            }
            // After reallocating, prompt for the new element to add
            printf("Enter data : ");
            scanf("%d", &n);
            (*queue)[rear] = n;
            rear++;
        } else {
            printf("You DO NOT wish to push any more elements.\n");
        }
    }
}

void dequeue(int** queue){
    if(front >= rear){
        printf("Queue is EMPTY!!!\n");
    }
    else{
        for(int i = 0; i < rear - 1; i++){
            (*queue)[i] = (*queue)[i+1];
        }
        rear--;
    }
}

void firstElement(int** queue){
    if(front >= rear){
        printf("Queue is EMPTY!!!\n");
    }
    else{
       printf("Front element is: %d\n", (*queue)[front]) ;
    }
}

void display(int** queue){
    if(front >= rear){
        printf("Queue is EMPTY!!!\n");
    }
    else{
        printf("Queue elements are: ");
        for(int i = front; i < rear; i++){
            printf("%d ", (*queue)[i]);
        }
        printf("\n");
    }
}

void qSize(int** queue){
    int count;
    if(front >= rear){
        printf("Queue is EMPTY!!!\n");
    }
    else{
        count = rear - front;
        printf("Queue size is: %d\n", count);
    }
}
