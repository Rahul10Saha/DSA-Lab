#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node {
  int item;
  struct node *left, *right;
}Tree;

Tree* root = NULL;
//creates new node
Tree *create_node(int num){
	Tree *new_node;
	new_node=(Tree *)malloc(sizeof(Tree));
	new_node->item = num;
	new_node->left = new_node->right = NULL;
	return new_node;
};

//Funtion for Inorder traversal
void inorder_traversal(Tree* root) {
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    printf("%d ", root->item);
    inorder_traversal(root->right);
}

Tree* insert_node(Tree* root, int val){
    if (root == NULL) //If the tree is empty, return a new,single node
        return create_node(val); 
    if (val < root->item)
        root->left = insert_node(root->left, val);
    else
        root->right = insert_node(root->right, val);
    return root;//return the (unchanged) root pointer
    
}

//Function to find the inorder successor
struct node *inorder_successor(Tree *node) {
  Tree*current = node;
  while (current && current->left != NULL)//Finds the leftmost leaf
    current = current->left;
  return current;
}

Tree* delete_node(Tree *root,int val){
    if(root==NULL){
        printf("\n\nValue not found");
        return root;
    }
    if(val < root->item)
        root->left=delete_node(root->left,val);
    else if(val > root->item)
        root->right=delete_node(root->right,val);
    else{
        if(root->left==NULL && root->right==NULL){//Node with no elements
            free(root);
            return NULL;
        }
        else if(root->left == NULL) {//Node with one element
            Tree* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {//Node with one element
            Tree* temp = root->left;
            free(root);
            return temp;
        }
        //Node with more than two children 
        Tree* temp = inorder_successor(root->right);
        root->item = temp->item;//Placing the inorder successor in position of the node to be deleted
        root->right = delete_node(root->right, temp->item);//Deleting the inorder successor
    }
  return root;
}

void search(Tree *root, int val, Tree *parent){
    if(root==NULL){
        printf("\n\nValue not found");
        return;
    }
    if(val==root->item){
        if(parent==NULL)
            printf("\n\nThe node with value %d is root node",val);
        else if(val<parent->item)
            printf("\n\nThe node node with value %d is the left child of the parent node %d",val,parent->item);
        else   
            printf("\n\nThe node node with value %d is the right child of the parent node %d",val,parent->item);
        return;
    }
    else if(val<root->item)
        return search(root->left,val,root);
    return(search(root->right,val,root));
}

void create_tree(){
    system("cls");
    int val;
    char ch;
    printf("\t\tBinary search tree creation");
    do{
        printf("\n\nEnter the node value:");
        scanf("%d",&val);
        root=insert_node(root,val);
        printf("\nThe inorder traversal of the tree is------>  ");
        inorder_traversal(root);
        printf("\nDo you want to enter more nodes(press 'Y' for yes and 'N' for no):");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='Y'||ch=='y');
}
int main(){
   int ch;
    do{
        system("cls");
        int val;
        Tree* node=NULL;
        printf("\t\tBinary Search tree and Its various operations\n\n");
        printf("1. Binary Search tree creation\n\n");
        printf("2. Binary search tree deletion\n\n");
        printf("3. Binary search tree search\n\n");
        printf("4. Show binary search tree(inorder traversal)\n\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: 
            create_tree();
            break;
        case 2: system("cls");
            printf("\t\tBinary Search Tree Deletion operation\n\n");
            printf("Enter the value of the Node to be deleted: ");
            scanf("%d",&val);
            printf("\n\nThe Binary Search Tree before Deletion---->");
            inorder_traversal(root);
            delete_node(root,val);
            printf("\n\nThe Binary Search Tree after Deletion---->");
            inorder_traversal(root);
            getch();
            break;
        case 3:  system("cls");
            printf("\t\tBinary Search Tree Searching operation\n\n");
            printf("Enter the value of the Node to be Searched: ");
            scanf("%d",&val);
            search(root,val,NULL);
            getch();
            break;
        case 4:
            system("cls");
            printf("\t\tDisplaying the Binary search tree\n\n");
            inorder_traversal(root);
            getch();
            break;
        case 0: exit(0);
            break;
        default: printf("Enter valid choice");
        }

    }while(1);
}

