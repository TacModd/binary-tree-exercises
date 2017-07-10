#include <stdio.h>
#include <stdlib.h>

#include "treedefinitions.c"
#include "traversal.c"

// main
int main() {
    node *tree = NULL;
    insert(3, &tree);
    printf("%i\n", tree->n);
    
    insert(4, &tree);
    insert(1, &tree);
    insert(6, &tree);
    insert(2, &tree);
    insert(0, &tree);
    insert(9, &tree);
    insert(5, &tree);
    
    pretrav(tree);
    printf("\n");
    
    intrav(tree);
    printf("\n");
    
    posttrav(tree);
    printf("\n");
    
    leveltrav(tree);
    printf("\n");
    
    printf("%i\n", search(3, tree));
    printf("%i\n", search(1, tree));
    printf("%i\n", search(0, tree));
    printf("%i\n", search(9, tree));
    
    printf("%i\n", height(tree));
    
    delet(5, &tree);
    delet(1, &tree);
    leveltrav(tree);
    printf("\n");
    
    delet(3, &tree);
    printf("%i\n", tree->n);
    leveltrav(tree);
    printf("\n");
    
    printf("%i\n", height(tree));
    
    freetree(tree);
    // attempting to print should return garbage value
    printf("%i\n", tree->n);
  
    /**
     * Note: tree should be set to NULL here, either following memory clearance in the 
     * function or in main, otherwise it will retain its pointer to a random location 
     * in memory. In a large program, if this pointer were reaccessed, it could corrupt 
     * data if the location had since been written to by another part of the program 
     * (setting to NULL throws location away).
     */
    
    return 0;
}
