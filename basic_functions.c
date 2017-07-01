#include <stdio.h>
#include <stdlib.h>

/* DEFINITIONS */

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

// binary tree struct
typedef struct node
{
    int n;
    struct node* left;
    struct node* right;
} node;



/* FUNCTIONS */


// binary tree search function
int search(int value, node* treepointer)
{
    if (treepointer == NULL)
    {
        return 0;
    }
    else if (value < treepointer->n)
    {
        return search(value, treepointer->left);
    }
    else if (value > treepointer->n)
    {
        return search(value, treepointer->right);
    }
    else
    {
        return 1;
    }
}


// binary tree add element function
node* insert(int value, node* treepointer)
{
    if (treepointer == NULL)
    {
        treepointer = malloc(sizeof(node));
        treepointer->n = value;
    }
    else if (value <= treepointer->n)
    {
        insert(value, treepointer->left);
    }
    else
    {
        insert(value, treepointer->right);
    }
    return treepointer;
}


// height
int height(node* treepointer)
{
    if (treepointer == NULL)
    {
        return -1;
    }
    else
    {
        return MAX(height(treepointer->right), height(treepointer->left)) + 1;
    }
}


// traversal functions
// preorder (DFS)
void pretrav(node* treepointer)
{
    if (treepointer != NULL)
    {
        printf("%i\n", treepointer->n);
        pretrav(treepointer->left);
        pretrav(treepointer->right);
    }
}


// inorder
void intrav(node* treepointer)
{
    if (treepointer != NULL)
    {
        intrav(treepointer->left);
        printf("%i\n", treepointer->n);
        intrav(treepointer->right);
    }
}


// postorder
void posttrav(node* treepointer)
{
    if (treepointer != NULL)
    {
        posttrav(treepointer->left);
        posttrav(treepointer->right);
        printf("%i\n", treepointer->n);
    }
}


// levelorder (BFS)




// main
int main() {
    node *tree = NULL;
    tree = insert(9, tree);
    printf("%i\n", tree->n);
    printf("%i\n", search(9, tree));
    return 0
}
