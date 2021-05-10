
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

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

//checkes if the tree is stricty binary
bool check_strict_binary(Tree *root) {
	if (root == NULL)// Check if tree is empty
		return true;

	if (root->left == NULL && root->right == NULL)// Check if children are present
		return true;

	if ((root->left) && (root->right))
		return (check_strict_binary(root->left) && check_strict_binary(root->right));

	return false;
}

//checkes if the tree is complete binary
bool check_complete_binary(Tree *root, int index, int numberNodes) {
	if (root == NULL)// Check if the tree is complete
		return true;

	if (index >= numberNodes)
		return false;

	return (check_complete_binary(root->left, 2 * index + 1, numberNodes) && check_complete_binary(root->right, 2 * index + 2, numberNodes));
}

//driver code
int main(){
	system("cls");
	printf("\t\tCheck is a Binary Tree is Scritly Binary or Complete Binary\n\n");
	int val,num_nodes,index=0;
	printf("Enter the number of nodes you want to enter:");
	scanf("%d",&num_nodes);
	printf("\n\nEnter the first Node:");
	scanf("%d",&val);
	root=create_node(val);
	printf("\n\nEnter the node data in format 'data' 'root_node(i.e the node under which you want to attach)' 'left(l) or right chid(r)'");
	for(int i=1;i<num_nodes;i++){
		create_tree();
	}
	if(check_strict_binary(root)){
        printf("\n\nThe tree is a Strictly Binary Tree");
    }
    else{
        printf("\n\nThe tree is not a Strictly Binary Tree");
    }
    if(check_complete_binary(root,index,num_nodes)){
        printf("\n\nThe tree is a Complete Binary Tree");
    }
    else{
        printf("\n\nThe tree is not a Complete Binary Tree\n\n");
    }
    return 0;
}
