#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct node *root = NULL;

void insert(int item)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;
    newnode->data = item;
    newnode->lchild = NULL;
    newnode->rchild = NULL;

    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        parent = root;
        while (1)
        {
            if (item < parent->data)
            {

                if (parent->lchild == NULL)
                {
                    parent->lchild = newnode;
                    return;
                }
                else
                {
                    parent = parent->lchild;
                }
            }
            else if (item > parent->data)
            {
                if (parent->rchild == NULL)
                {
                    parent->rchild = newnode;
                    return;
                }
                else
                {
                    parent = parent->rchild;
                }
            }
            else
            {
                return;
            }
        }
    }
}
void deleteNode(struct node *root, int value)
{
    struct node *temp = root;
    struct node *temp2;
    while (temp->data != value)
    {
        temp2 = temp;
        if (temp->data > value && temp->lchild != NULL)
        {
            temp = temp->lchild;
        }
        else if (temp->data < value && temp->rchild != NULL)
        {
            temp = temp->rchild;
        }
    }
    if (temp->lchild == NULL && temp->rchild == NULL)
    {
        if (temp2->data > value)
            temp2->lchild = NULL;

        else if (temp2->data < value)
        {
            temp2->rchild = NULL;
        }
        free(temp);
    }
    else if ((temp->lchild == NULL) ^ (temp->rchild == NULL))
    {
        if (temp2->data > value)
        {
            if ((temp->lchild == NULL))
            {
                temp=temp->rchild;
            }
            else
            {
                temp=temp->lchild;
            }
        }

        else if (temp2->data < value)
        {
            temp2->rchild = (temp->lchild == NULL) ? temp->rchild : temp->lchild;
        }
        free(temp);
    }
    
}
// void deleteNode(struct node *root, int key)
// {
//     // Return if the tree is empty

//     if (root == NULL)
//     {
//         printf("No root is available");
//     }

//     // Find the node to be deleted
//     if (key < root->data)
//     {
//         deleteNode(root->lchild, key);

//     }
//     else if (key > root->data)
//     {
//         deleteNode(root->rchild, key);
//     }
//     else
//     {
//         if (root->lchild == NULL && root->rchild==NULL)
//         {
//             free(root);

//         }
//         else if (root->lchild == NULL)
//         {
//             struct node *temp = root->rchild;
//             // root->data=temp->data;
//             free(root);
//             return;
//         }
//         else if (root->rchild == NULL)
//         {
//             struct node *temp = root->lchild;
//             // root->data=temp->data;
//             free(root);
//             return;
//         }

//     }

// }

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf("%d  ", root->data);
        inorder(root->rchild);
    }
};

int main()
{
    int choice, item, k;
    while (1)
    {
        printf("Enter 1 to insert\n");
        printf("Enter 2 to delete \n");
        printf("Enter 3 to exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Insert the element which u want to insert in tree : ");
            scanf("%d", &item);
            insert(item);
            inorder(root);
            printf("\n");
            break;
        case 2:
            printf("Enter the element which u want to delete in tree : ");
            scanf("%d", &k);
            deleteNode(root, k);
            inorder(root);
            printf("\n");
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid\n");
        }
    }
}
