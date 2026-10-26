#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enque(int val)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = val;
}

void deque()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
        {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        int choice, val;
        printf("Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enque(val);
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}