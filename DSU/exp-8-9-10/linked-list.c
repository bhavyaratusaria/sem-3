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
    printf("First element deleted.\n");
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
        printf("Last element deleted.\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Last element deleted.\n");
}

void deleteAfter(int afterData)
{
    struct Node *temp = head;

    while (temp != NULL && temp->data != afterData)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element %d not found in the list\n", afterData);
        return;
    }

    if (temp->next == NULL)
    {
        printf("No element exists after %d to delete.\n", afterData);
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Element after %d has been deleted.\n", afterData);
}

void mergeLists()
{
    int val;
    struct Node *head2 = NULL;
    struct Node *temp2 = NULL;

    printf("Enter elements for the second list (enter -1 to stop): \n");
    while (1)
    {
        printf("Enter num: ");
        scanf("%d", &val);
        if (val == -1)
            break;

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head2 == NULL)
        {
            head2 = newNode;
            temp2 = head2;
        }
        else
        {
            temp2->next = newNode;
            temp2 = newNode;
        }
    }

    if (head == NULL)
    {
        head = head2;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head2;
    }
    printf("Lists merged successfully!\n");
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
    int choice, n, pos, afterData;
    while (1)
    {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Insert After\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete After\n");
        printf("8. Display\n");
        printf("9. Count Nodes\n");
        printf("10. Search\n");
        printf("11. Merge Two Lists\n");
        printf("12. Exit\n");
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
            printf("Enter num and position (space separated): ");
            scanf("%d %d", &n, &pos);
            insertAtPos(n, pos);
            break;
        case 4:
            printf("Enter num to insert and element to insert after (space separated): ");
            scanf("%d %d", &n, &afterData);
            insertAfter(n, afterData);
            break;
        case 5:
            deleteAtBeg();
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            printf("Enter element after which you want to delete: ");
            scanf("%d", &afterData);
            deleteAfter(afterData);
            break;
        case 8:
            display();
            printf("Null\n");
            break;
        case 9:
            count();
            break;
        case 10:
            printf("Enter element to search: ");
            scanf("%d", &n);
            search(n);
            break;
        case 11:
            mergeLists();
            break;
        case 12:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}