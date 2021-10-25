#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *right, *left;
};

struct node* create(int );
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
int height(struct node*);
void levelorder(struct node*);
void printLevel(struct node*, int);

int arr[100],n;

struct node* create(int index)
{
	struct node *newNode=NULL;
	if(index<n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->left=create(2*index+1);
		newNode->data=arr[index];
		newNode->right=create(2*index+2);
	}
	return newNode;
}

void inorder(struct node *Node)
{
	if(Node!=NULL)
	{
		inorder(Node->left);
		printf("%d ", Node->data);
		inorder(Node->right);
	}
}

void preorder(struct node *Node)
{
	if(Node!=NULL)
	{
		printf("%d ",Node->data);
		preorder(Node->left);
		preorder(Node->right);
	}
}

void postorder(struct node *Node)
{
	if(Node!=NULL)
	{
		postorder(Node->left);
		postorder(Node->right);
		printf("%d ",Node->data);
	}
}

int height(struct node *Node)
{
	if(Node==NULL)
		return 0;
	else
	{
		int LSTheight=height(Node->left);
		int RSTheight=height(Node->right);
		
		if(LSTheight>RSTheight)
			return LSTheight+1;
		else
			return RSTheight+1;
	}
}

void printLevel(struct node *Node, int level)
{
	if(Node!=NULL)
	{
		if(level==1)
			printf("%d ",Node->data);
		else
		{
			printLevel(Node->left,level-1);
			printLevel(Node->right,level-1);
		}
	}
}

void levelorder(struct node* root)
{
	int h=height(root);
	for(int i=1;i<=h;i++)
		printLevel(root,i);
}

int main()
{
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	struct node *root=create(0); // creating a tree from the array
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	levelorder(root);
	return 0;
}
