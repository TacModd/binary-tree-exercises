#include <stdio.h>
#include <stdlib.h>

/**
 * Note: this file requires "basic_functions.c" to work
 */



/* FUNCTIONS */


/**
 * pre order (DFS) tree traversal
 */
void pretrav(node* treepointer)
{
    if (treepointer != NULL)
    {
        printf("%i\n", treepointer->n);
        pretrav(treepointer->left);
        pretrav(treepointer->right);
    }
}


/**
 * in order tree traversal
 */
void intrav(node* treepointer)
{
    if (treepointer != NULL)
    {
        intrav(treepointer->left);
        printf("%i\n", treepointer->n);
        intrav(treepointer->right);
    }
}


/**
 * post order tree traversal
 */
void posttrav(node* treepointer)
{
    if (treepointer != NULL)
    {
        posttrav(treepointer->left);
        posttrav(treepointer->right);
        printf("%i\n", treepointer->n);
    }
}


// level order traversal helper prototype
void printLevel(node* treepointer, int level);

/**
 * level order tree traversal (BFS) -- recursive implementation
 */
void leveltrav(node* treepointer)
{
    int h = height(treepointer);
    int i;
    for (i=1; i<=h; i++)
        // call helper passing value of current level
        printLevel(treepointer, i);
}

/**
 * level order tree traversal helper
 */
void printLevel(node* treepointer, int level)
{
    if (treepointer == NULL)
        return;
    if (level == 1)
        printf("%i\n", treepointer->n);
    else if (level > 1)
    {
        // explore subtrees until all nodes for current level are printed
        printLevel(treepointer->left, level - 1);
        printLevel(treepointer->right, level - 1);
    }
}
