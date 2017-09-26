#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

/** Program to demonstrate the Tree and Tnode class and their methods.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to these words.
 */
int main(int argc, char* argv[]) {

  
  printf("\nCreating a tree...\n");
  
  Tree* newTree = new Tree();

  
  printf("\nPart 3\n");

  printf("Adding data to the tree...\n");
  
  newTree->add("adonay");
  newTree->add("krishna");
  newTree->add("yared");
  newTree->add("basleal");
  newTree->add("kidus");
  
  Tnode* node = newTree-> root;
  
  Tnode* noder = node->right;

  
  Tnode* nodel = noder->left;
  
  const char* first = node->data;

  const char* fleft = nodel->data;
  const char* fright = noder->data;
  
  printf("\n\n%s\n\nRight:%s\n\nLeft:%s\n\n", first, fright, fleft);

  
  printf("\nPart 4\n");
  
  printf("\nPrint the tree in ascending order using inorder transversal:\n");
  
  newTree->printAscending();

  printf("\nPart 6\n");

  printf("\nFree all nodes from the tree in using postorder transversal...\n");

  newTree->freeTree();

  printf("\nPrinting tree again to demonstrate freeTree():\n");
  
  newTree->printAscending();
 

  delete(newTree);
  
  return 0; //indicates success
  
}
