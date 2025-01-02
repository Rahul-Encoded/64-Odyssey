#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node *root = NULL;

void createNode(int n) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL) {
        root = newNode;
    } 
    
    else {
        struct Node* temp = root;
        struct Node* parent = NULL;

        while(temp != NULL) {
            parent = temp;
            if(n < temp->data) {
                temp = temp->left;
            } 
            else if(n > temp->data){
                temp = temp->right;
            }
            else{
                break;
            }
        }

        if(n < parent->data) {
            parent->left = newNode;
        } 
        else if(n > parent->data) {
            parent->right = newNode;
        }
        else{
            printf("\nYOU CAN'T RE-ENTER THE SAME ELEMENT IN A BST!!!\n");
        }
    }
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

void delNode(int n){
    if(root == NULL) printf("\nThe Tree is EMPTY!!!\n");
    
    else{
        struct Node *temp = root;
        struct Node *parent = NULL;
        while(temp != NULL && temp->data != n){
            parent = temp;
            if(n < temp->data){
                temp = temp->left;
            }
            else if(n > temp->data){
                temp = temp->right;
            }
        }
        if(temp == NULL){
            printf("\nThe ELEMENT you wish to delete DOESN'T EXIST!!!\n");
        }
        else{
            if(temp->left == NULL && temp->right == NULL){
                //Node to be deleted is a leaf node
                if(n < parent -> data){
                    parent->left = NULL;
                }
                else{
                    parent->right = NULL;
                }
                free(temp);
            }
            else if(temp->left == NULL || temp->right == NULL){
                //Node To be deleted has a child
                struct Node *temp2 = temp;
                if(temp->left == NULL && temp->right != NULL){
                    temp2 = temp2->right;
                }
                else if(temp->left != NULL && temp->right == NULL){
                    temp2 = temp2->left;
                }

                if(temp == parent->left){
                    parent->left = temp2;
                }
                else if(temp == parent->right){
                    parent->right = temp2;
                }
                free(temp);        
            }
            else{
                //Node to be deleted has 2 chilren
                struct Node* temp2 = temp;
                struct Node* parent2 = NULL;
                int ch;
                printf("\nEnter your choice of deletion:\n");
                printf("1. The deleted element will be replaced by it's in-order predecessor.\n");
                printf("2. The deleted element will be replaced by it's in-order successor.\n");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                    while(temp2->right != NULL){
                        parent2 = temp2;
                        temp2 = temp->right;
                    }
                    temp->data = temp2->data;
                    parent2->right = NULL;
                    free(temp2);
                    break;
                
                case 2:
                    while(temp2->left != NULL){
                        parent2 = temp2;
                        temp2 = temp->left;
                    }
                    temp->data = temp2->data;
                    parent2->left = NULL;
                    free(temp2);
                    break;

                default:
                    printf("Enter a valid choice!!!");
                }
            }
        }
    }

}

int search(int n){
    struct Node* temp = root;
    while(temp->data != n || temp != NULL){
        if(temp->data == n){
            return 1;
            break;
        }
        else if(temp->data < n){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return 0;

/*int search(struct Node* root, int n){
    if(root == NULL) return 0;

    else if(n == root->data) return 1;

    else if(n < root->data) return search(root->left, n);

    else return search(root->right, n);
}

*/
}


int main() {
    int choice;
    do {
        int n;
        printf("Which operations do you wish to perform on the BST:\n");
        printf("1. Create Node\n");
        printf("2. Pre-order Traversal\n");
        printf("3. In-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Deletion of a node\n");
        printf("6. Check if an element is in the BST\n");
        printf("7. END\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int ele;
                printf("Enter the element you wish to push in your BST: ");
                scanf("%d", &ele);
                createNode(ele);
                break;
            }
            case 2:
                preOrder(root);
                printf("\n");
                break;
            case 3:
                inOrder(root);
                printf("\n");
                break;
            case 4:
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the element you wish to delete: ");
                scanf("%d ", &n);
                delNode(n);
                break;

            case 6:
                printf("Enter the element you wish to find: ");
                scanf("%d", &n);
                if(search(n)) printf("The Element you entered exists in the BST!");
                else printf("The element you entered doesn't exist in the BST!");

            case 7:
                exit(0);

            default:
                printf("Enter a valid choice!!!\n");
        }
    } while(1);

    return 0;
}
