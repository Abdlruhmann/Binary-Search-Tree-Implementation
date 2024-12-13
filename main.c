#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * root=NULL;

struct Node * CreateNode(int data) {
    struct Node * ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));

    if(ptr) {
        ptr->data=data;
        ptr->left=NULL;
        ptr->right=NULL;
    }
    return ptr;
}

int InsertNode(int data) {
    int retval=0;
    struct Node * ptr;
    struct Node * temp=root;
    struct Node * parent=NULL;
    ptr = CreateNode(data);

    if(ptr) {
        retval=1;
        if(!root) {
            root=ptr;
        }else {
            while(temp) {
                parent=temp;
            
                if(data < temp->data) {
                    temp=temp->left;
                }else {
                    temp=temp->right;
                }
            }
              if (data < parent->data) {
                parent->left = ptr; 
            } else {
                parent->right = ptr; 
            }
        }
    }
    return retval;
}

void InOrderTraverse(struct Node * root) {
    if(root) {
        InOrderTraverse(root->left);
        printf("%d\n", root->data);
        InOrderTraverse(root->right);
    }
}

void PreOrderTraverse(struct Node * root) {
    if(root){
        printf("%d\n", root->data);
        PreOrderTraverse(root->left);
        PreOrderTraverse(root->right);
    }
}

void PostOrderTraverse(struct Node * root) {
    if(root) {
        PostOrderTraverse(root->left);
        PostOrderTraverse(root->right);
        printf("%d\n", root->data);
    }
}

void Menu() {
    printf("1. Insert Node. \n");
    printf("2. In Order. \n");
    printf("3. Pre Order. \n");
    printf("4. Post Order. \n");
    printf("5. Exit. \n");
}
int main()
{   
    int choice;
    int running = 1;
    int num_of_inputs;

    do {
        Menu();
        printf("Please Enter Your Choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: {
            printf("Enter number of nodes want to insert: \n");
            scanf("%d", &num_of_inputs);
            int inserted=0;
            int input;
            for(int i = 0 ; i < num_of_inputs; i++) {
                printf("Enter The %d Number to insert : \n", i + 1);
                scanf("%d", &input);
                inserted=InsertNode(input);
            }
            if(inserted) {
                printf("_____OUTPUT_____\n");
                printf("Data Inserted Successfuly to the tree.\n");
                printf("________________\n");
            }else {
                printf("Error While Inserting.\n");
            }
            break;
        }
        
        case 2:
        printf("_____OUTPUT_____\n");
        InOrderTraverse(root);
        printf("________________\n");
        break;

        case 3:
        printf("_____OUTPUT_____\n");
        PreOrderTraverse(root);
        printf("________________\n");
        break;

        case 4:
        printf("_____OUTPUT_____\n");
        PostOrderTraverse(root);
        printf("________________\n");
        break;
        
        case 5:
        printf("Existing the program..\n");
        running=0;
        break;

        default:
            printf("Invalid Choice.\n");
            break;
        }
    }while(running);

    return 0;
}
