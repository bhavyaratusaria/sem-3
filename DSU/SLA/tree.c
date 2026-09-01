#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Step 1: Define the structure for a tree node
struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

// Step 2: Create a new node
struct Node *createNode(char val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Step 3: Build the expression tree from a postfix string
struct Node *buildExpressionTree(char postfix[])
{
    struct Node *stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char c = postfix[i];

        // If the character is an operand (number/letter), create node and push to stack
        if (isalnum(c))
        {
            stack[++top] = createNode(c);
        }
        // If it is an operator, pop two nodes, make them children, and push back
        else
        {
            struct Node *newNode = createNode(c);
            newNode->right = stack[top--]; // Pop right child first
            newNode->left = stack[top--];  // Pop left child next
            stack[++top] = newNode;
        }
    }
    // The last remaining node is the root of the tree
    return stack[top];
}

// Step 4: Evaluate the expression tree recursively
int evaluate(struct Node *root)
{
    // If tree is empty
    if (root == NULL)
        return 0;

    // If leaf node, convert character digit to integer value
    if (root->left == NULL && root->right == NULL)
    {
        return root->data - '0'; // Works for single-digit numbers '0' to '9'
    }

    // Evaluate left and right subtrees
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    // Apply the operator at the current node
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
    default:
        return 0;
    }
}

// Step 5: Print tree using Inorder Traversal (adds parentheses to show structure)
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
    // Example postfix expression: 3 4 + 2 *  (which means (3 + 4) * 2)
    char postfix[] = "34+2*";

    struct Node *root = buildExpressionTree(postfix);

    printf("Inorder expression: ");
    inorder(root);
    printf("\n");

    int result = evaluate(root);
    printf("Evaluated Result: %d\n", result);

    return 0;
}