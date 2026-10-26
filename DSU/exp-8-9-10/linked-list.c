#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeg(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPos(int data, int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAfter(int data, int afterData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *temp = head;
    while (temp != NULL && temp->data != afterData)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element %d not found in the list\n", afterData);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

void count()
{
    struct Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("count = %d\n", count);
}

void deleteAtBeg()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}
void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void search(int data)
{
    struct Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Element %d found at position %d\n", data, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found in the list\n", data);
}

int main()
{
    int choice, n, pos;
    while (1)
    {
        printf("Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("8. Delete at Beginning\n");
        printf("9. Delete at End\n");
        printf("10. Display\n");
        printf("11. Count\n");
        printf("12. Search\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter num: ");
            scanf("%d", &n);
            insertAtBeg(n);
            break;
        case 2:
            printf("Enter num: ");
            scanf("%d", &n);
            insertAtEnd(n);
            break;
        case 3:
            printf("Enter num and position: ");
            scanf("%d, %d", &n, &pos);
            insertAtPos(n, pos);
            break;
        case 4:
            deleteAtBeg();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            display();
            printf("Null\n");
            break;
        case 7:
            count();
            break;
        case 8:
            printf("Enter element to search: ");
            scanf("%d", &n);
            search(n);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice.");
        }
    }
    return 0;
}