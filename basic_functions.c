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


/**
 * binary tree search function (returns 0 for failure, 1 for success)
 */
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

/**
 * binary tree add element function (returns tree root)
 */
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

/**
 * binary tree remove element function (returns 0 for failure, 1 for success)
 */
int delet(int value, node* treepointer)
{
    // declare pointer which will identify the node to delete
    node* child = treepointer;
    // declare pointer which will track parent node (makes tree easier to fix after deletion)
    node* parent = treepointer;
    // declare integer which will track the path of said parent to child (left or right)
    int isLeft = 0;
    
    // while value undiscovered
    while (child->n != value)
    {
        // update parent to child
        parent = child;
        // update child to next descendant and update path taken
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
        // if NULL is reached, node with given value does not exist in tree
        if (child == NULL)
        {
            return 0;
        }
    }
    
    // if while loop exits then node is discovered and needs to be deleted
    
    // if node is a leaf...
    if (child->left == NULL && child->right == NULL)
    {
        // if node is the root then delete tree
        if (child == treepointer)
        {
            treepointer = NULL;
        }
        
        // else delete edge pointing to node
        
        else if (isLeft == 1)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
    }
    
    // else if node has one child, update parent to point to descendant
    
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
        else if (isLeft == 1)
        {
            parent->left = child->right;
        }
        else
        {
            parent->right = child->right;
        }
    }
    
    // else if node to delete has two children
    else
    {
        // identify a suitable replacement node
        node* replacement = deletHelper(child);
        
        // make root replacement or update parent to point to replacement
        
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
        
        // update replacement to point to left subtree (helper takes care of right subtree)
        replacement->left = child->left;
    }
    
    // return success
    return 1;
}

/**
 * binary tree remove element helper function (returns replacement node)
 */
node* deletHelper(node* deletThis)
{
    // declare replacement ("child") pointer
    node* replacement = NULL;
    // declare pointer to track parent
    node* parent = NULL;
    // declare pointer to search grandchildren
    node* grandchild = deletThis->right;
    
    // while there are descendants to search...
    while (grandchild != NULL)
    {
        // update parent to child
        parent = replacement;
        // update child to grandchild
        replacement = grandchild;
        // search left grandchild
        grandchild = grandchild->left;
    }
    
    /**
     * note: the decision to go right and then left to find a replacement is 
     * arbitrary; going left and then right also works and may have produced 
     * a more 'suitable' replacement depending on the size of both branches
     */
    
    // if replacement is a node other than the node to delete's immediate child...
    if (replacement != deletThis->right)
    {
        // update parent->left to replacement->right (there are no left children as per above loop)
        parent->left = replacement->right;
        // update replacement->right to deletThis->right (preserves subtree)
        replacement->right = deletThis->right;
    }
    
    // return replacement to main function
    return replacement;
}


/**
 * tree height function (returns -1 for empty tree, else the number of levels)
 */
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


/**
 * free memory function (post order traversal to visit all branches before the root)
 */
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
