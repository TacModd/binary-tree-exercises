#include <stdio.h>
#include <stdlib.h>

#include "basic_functions.c"



/* FUNCTIONS */


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


// levelorder traversal helper prototype
void printLevel(node* treepointer, int level)

// levelorder (BFS) recursive
void leveltrav(node* treepointer)
{
    int h = height(treepointer);
    int i;
    for (i=1; i<=h; i++)
        printLevel(treepointer, i);
}
 
// levelorder recursive traversal helper
void printLevel(node* treepointer, int level)
{
    if (treepointer == NULL)
        return;
    if (level == 1)
        printf("%i\n", treepointer->n);
    else if (level > 1)
    {
        printLevel(treepointer->left, level - 1);
        printLevel(treepointer->right, level - 1);
    }
}


int main() {
    
}
