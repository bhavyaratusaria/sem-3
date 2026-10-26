
#include <stdio.h>
#include <string.h>

#define MAX 20
#define SIZE 50

typedef struct
{
    char page[MAX][SIZE];
    int top;
} Stack;

/* Push a page onto the stack */
int push(Stack *s, const char page[])
{
    if (s->top == MAX - 1)
        return 0;

    strcpy(s->page[++s->top], page);
    return 1;
}

/* Pop a page from the stack */
int pop(Stack *s, char page[])
{
    if (s->top == -1)
        return 0;

    strcpy(page, s->page[s->top--]);
    return 1;
}

/* Display visited pages */
void showHistory(Stack *back, Stack *forward,
                 const char current[])
{
    int i;

    printf("\n--- BROWSER HISTORY ---\n");

    printf("Previously visited pages:\n");
    for (i = 0; i <= back->top; i++)
        printf("%s\n", back->page[i]);

    printf("Current page: %s\n", current);

    printf("Forward pages:\n");
    for (i = forward->top; i >= 0; i--)
        printf("%s\n", forward->page[i]);
}

/* Clear saved history */
void clearHistory(Stack *back, Stack *forward)
{
    back->top = -1;
    forward->top = -1;
    printf("Browser history cleared.\n");
}

int main(void)
{
    Stack back = {.top = -1};
    Stack forward = {.top = -1};

    char current[SIZE] = "Home";
    char page[SIZE];
    int choice;

    do
    {
        printf("\n--- BROWSER HISTORY NAVIGATOR ---\n");
        printf("Current page: %s\n", current);
        printf("1. Visit new page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. View history\n");
        printf("5. Clear history\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter page name (no spaces): ");

            if (scanf("%49s", page) != 1)
                break;

            if (push(&back, current))
            {
                strcpy(current, page);
                forward.top = -1;
                printf("Page opened successfully.\n");
            }
            else
            {
                printf("Back history is full. Cannot visit page.\n");
            }
            break;

        case 2:
            if (pop(&back, page))
            {
                if (push(&forward, current))
                    strcpy(current, page);
                else
                {
                    push(&back, page);
                    printf("Forward history is full.\n");
                }
            }
            else
            {
                printf("No previous page available.\n");
            }
            break;

        case 3:
            if (pop(&forward, page))
            {
                if (push(&back, current))
                    strcpy(current, page);
                else
                {
                    push(&forward, page);
                    printf("Back history is full.\n");
                }
            }
            else
            {
                printf("No forward page available.\n");
            }
            break;

        case 4:
            showHistory(&back, &forward, current);
            break;

        case 5:
            clearHistory(&back, &forward);
            break;

        case 6:
            printf("Exiting Browser History Navigator.\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
