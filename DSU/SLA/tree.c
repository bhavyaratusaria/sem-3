#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Expression Tree Creator and Evaluator (Using Binary Tree)
struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *buildExpressionTree(char postfix[])
{
    struct Node *stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char c = postfix[i];

        if (c >= '0' && c <= '9')
        {
            stack[++top] = createNode(c);
        }
        else
        {
            struct Node *newNode = createNode(c);
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }
    return stack[top];
}

int evaluate(struct Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
    {
        return root->data - '0';
    }

    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    switch (root->data)
    {
    case '+':
        return leftVal + rightVal;
    case '-':
        return leftVal - rightVal;
    case '*':
        return leftVal * rightVal;
    case '/':
        return leftVal / rightVal;
    case '^':
        return (int)pow(leftVal, rightVal);
    default:
        return 0;
    }
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        if (root->left || root->right)
            printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if (root->left || root->right)
            printf(")");
    }
}

int main()
{
    printf("Enter String: ");
    char str[10];
    scanf("%s", str);

    struct Node *root = buildExpressionTree(str);

    printf("Infix expression: ");
    inorder(root);
    printf("\n");

    int result = evaluate(root);
    printf("Evaluated Result: %d\n", result);

    return 0;
}