#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *previous;
    struct node *next;
};
struct node *head, *tail = NULL;

void addNode(int data)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (head == NULL)
    {

        head = tail = newNode;
        head->previous = NULL;
        tail->next = NULL;
    }
    else
    {

        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        tail->next = NULL;
    }
}

int reverse_array(int arr[], int start, int end)
{

    int temp;

    while (start < end)

    {

        temp = arr[start];
        arr[start] = arr[end];

        arr[end] = temp;
        start++;

        end--;
    }
    return temp;
}

void display()
{

    struct node *current = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // printf("Nodes of doubly linked list: \n");
    while (current != NULL)
    {

        // Prints each node by incrementing pointer.

        printf("%d\n", current->data);

        current = current->next;
    }
}

//Diver CODE.

int main()
{

    int n;

    scanf("%d", &n);

    int arr[n], even[n];
    int i, k = 0;
    for (i = 0; i < n; i++)
    {

        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)

        {

            even[k] = arr[i];

            k += 1;
        }
    }
    int st = 0;

    reverse_array(even, 0, k - 1);
    for (i = 0; i < n; i++)
    {

        if (arr[i] % 2 == 0)

        {

            addNode(even[st]);
            st += 1;
        }

        else

        {
            addNode(arr[i]);
        }
    }
    display();
    return 0;
}

//Time Complexity O(n) and space complexity O(n)