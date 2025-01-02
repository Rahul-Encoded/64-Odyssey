#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* root = NULL;

struct Node* createNode(int n){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

void preOrder(struct Node *root){
    if(root == NULL) return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node *root){
    if(root == NULL) return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(struct Node *root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int isBST(struct Node *root, int min, int max){
    if (root==NULL) return 1;
    //We can also check if a given BT is a BST, by inorder traversal and ensuring the elements are in a sorted manner. 

    if(root->data <= min || root->data >= max) return 0;

    return 
        isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

int isbst(struct Node *root){
    return isBST(root, INT_MIN, INT_MAX);
}

int main() {
    // Your code goes here
    struct Node* p0 = createNode(5);
    struct Node* p1 = createNode(1);
    struct Node* p2 = createNode(6);
    struct Node* p3 = createNode(9);
    struct Node* p4 = createNode(4);

    p0->left = p1;
    p0->right = p2;
    p1->right = p4;
    p2->right = p3;

    int choice;
    do{
        printf("\n1. Pre-order Traversal\n");
        printf("2. In-order Traversal\n");
        printf("3. Post-order Traversal\n");
        printf("4. check if BT is BST\n");
        printf("5. END\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            preOrder(p0);
            break;

        case 2:
            inOrder(p0);
            break;

        case 3:
            postOrder(p0);
            break;

        case 4:
            if(isbst(p0)) printf("YES! The given BT is a BST!!!");
            else printf("NO! The given BT is not a BST!!!");
            break;

        case 5:
            exit(0);

        default:
            printf("Enter a valid choice: ");
        }
    }while(1);
    
    return 0;
}