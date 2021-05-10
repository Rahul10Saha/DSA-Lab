#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100

//structure defining the tree
typedef struct node {
  int item;
  struct node *left, *right;
}Tree;

Tree *root=NULL;
//creates new node
Tree *create_node(int num)
{
	Tree *new_node;
	new_node=(Tree *)malloc(sizeof(Tree));
	new_node->item = num;
	new_node->left = new_node->right = NULL;
	return new_node;
};

//inserts as left child
void insert_left(Tree *new_root,int val)
{
	new_root->left=create_node(val);
}

//inserts as right child
void insert_right(Tree *new_root,int val){
	new_root->right=create_node(val);
}

//search for the root node given as input from the user
bool search_node(Tree *temp,int user_root, char a, int num){
  if(temp == NULL)
   return 0;
  if(temp->item == user_root  &&(temp->left==NULL || temp->right==NULL))
    {
     if(a == 'l' || a == 'L')//for left child
       {
         if(temp->left == NULL)
          {
           insert_left(temp, num);
           return 1;
          }
         else
           return 0;
       }
     else
       {
         if(temp->right == NULL)//for right child
          {
            insert_right(temp, num);
            return 1;
          }
        else
          return 0;
       }

    }
  else
   return search_node(temp->left, user_root, a, num) || search_node(temp->right, user_root, a, num);
}

//creates the tree
void create_tree(){
	char a;
	printf("\n\nEnter the node in format specified:");
	int num,user_root;
	scanf("%d %d %c",&num,&user_root,&a);
   	bool found = 0;
	if(a=='l'||a=='L'){
	  	found = search_node(root,user_root,a,num);

	}
	else if(a=='r'||a=='R'){
		found =search_node(root,user_root,a,num);
	}
  if(!found)
   printf("The parent node doesn't exist\n");
}

//Funtion for Inorder traversal
void inorder_traversal(Tree* root) {
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    printf("%d ", root->item);
    inorder_traversal(root->right);
}

//Funtion For Preorder Traversal
void preorder_traversal(Tree* root) {
    if (root == NULL)
        return;
    printf("%d ", root->item);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

//Function for Postorder Traversal
void postorder_traversal(Tree* root) {
    if (root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->item);
}

// Driver code
int main()
{
    system("cls");
    printf("\t\tInorder,Preorder,Postorder traversal\n\n");
    int val,num_nodes,index=0;
    printf("Enter the number of nodes you want to enter:");
    scanf("%d",&num_nodes);
    printf("\n\nEnter the first Node:");
    scanf("%d",&val);
    root=create_node(val);
    printf("\n\nEnter the node data in format 'data' 'parent_node(i.e the node under which you want to attach)' 'left(l) or right chid(r)'");
    for(int i=1;i<num_nodes;i++){
      create_tree();
    }

    printf("\n\nInorder traversal \n");
    inorder_traversal(root);

    printf("\n\nPreorder traversal \n");
    preorder_traversal(root);

    printf("\n\nPostorder traversal \n");
    postorder_traversal(root);
}
