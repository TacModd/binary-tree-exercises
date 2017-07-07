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


// binary tree remove element helper prototype
node* deletHelper(node* deletThis)

// binary tree remove element function
int delet(int value, node* treepointer)
{
    node* parent = treepointer;
    node* child = treepointer;
    int isLeft = 0;
    
    while (child->n != value)
    {
        parent = child;
        if (value <= child->n)
        {
            isLeft = 1;
            child = child->left;
        }
        else
        {
            isLeft = 0;
            child = child->right;
        }
        if (child == NULL)
        {
            return 0;
        }
    }
    
    if (child->left == NULL && child->right == NULL)
    {
        if (child == treepointer)
        {
            treepointer = NULL;
        }
        else if (isLeft == 1)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
    }
    
    else if (child->right == NULL)
    {
        if (child == treepointer)
        {
            treepointer = child->left;
           }
        else if (isLeft == 1)
        {
            parent->left = child->left;
        }
        else
        {
            parent->right = child->left;
        }
    }
    
    else if (child->left == NULL)
    {
        if (child == treepointer)
        {
            treepointer = child->right;
        }
        else if (isLeft == 0)
        {
            parent->left = child->right;
        }
        else
        {
            parent->right = child->left;
        }
    }
    
    else
    {
        node* replacement = terminateHelper(child);
    
        if (child == treepointer)
        {
            treepointer = replacement;
        }
        else if (isLeft == 1)
        {
            parent->left = replacement;
        }
        else
        {
            parent->right = replacement;
        }
    
        replacement->left = child->left;
    }
    
    return 1;
}

// binary tree remove element helper function
node* deletHelper(node* deletThis)
{
    node* replacement = NULL;
    node* parent = NULL;
    node* grandchild = deletThis->right;
    
    while (grandchild != NULL)
    {
        parent = replacement;
        replacement = grandchild;
        grandchild = grandchild->left;
    }
    
    if (replacement != deletThis->right)
    {
        parent->left = replacement->right;
        replacement->right = deletThis->right;
    }
    
    return replacement;
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


// function to free memory (postorder)
void freetree(node* treepointer)
{
  if (treepointer != NULL)
  {
    posttrav(treepointer->left);
    posttrav(treepointer->right);
    free(treepointer);
  }
}


// main
int main() {
    node *tree = NULL;
    tree = insert(9, tree);
    printf("%i\n", tree->n);
    printf("%i\n", search(9, tree));
    return 0
}
