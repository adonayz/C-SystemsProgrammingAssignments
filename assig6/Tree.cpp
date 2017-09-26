#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tree.h"

/** Default constructor for GeneralNumber
 */
Tree::Tree() {
  root = NULL;
}

/** Adds given string (C style) to a newly instantiated node and adds 
 * it to the tree if the tree is empty. If the tree is not empty,
 * it calls the add function on the root Tnode.
 * @param data C style string to add to tree as data
 */
void Tree::add(const char* data){
  if(root == NULL){
    root = new Tnode(data);
  }else{
    root->add(data);
  }
}

/**Prints the tree in ascending order of values using inorder transversal
 * on the tree. Has a helper function which accepts a node and prints 
 * recursion. This is the main function that is used to print the tree.
 */
void Tree::printAscending() const{
  if(root == NULL){
    printf("\nThis tree is empty!\n\n");
    return;
  }else{
    printAscendingHelper(root);
  }
}

/**This is a helper function that prints the tree in ascending order of 
 * values using inorder transversal on the tree. Uses recursion for inorder
 * transversal. This function should not be called because it is a helper 
 * function.
 * @param node Is the root node of the tree you want to print
 */
void Tree::printAscendingHelper(Tnode* node) const {
   if(node == NULL){
    return;
   }else{
    printAscendingHelper(node->left);
    printf("Node data: %s\n", node->data);
    printAscendingHelper(node->right);
   }
}

/**Frees the nodes in the tree using postorder transversal. This function
 * has a helper function which accepts a node and uses postorder transveral
 * by recursion to free all nodes that brach out from the given node. If
 * tree is empty, it prints an appropriate message.
 */
void Tree::freeTree(){
  if(root == NULL){
    printf("\nThis tree is empty!\n\n");
    return;
  }else{
    freeTreeHelper(root);
  }
}

/**Accepts a node and uses postorder transveral by recursion to free
 * all nodes that brach out from the given node. This function should 
 * not be called because it is a helper function.
 * @param node Is the root node of the tree you want to free
 */
void Tree::freeTreeHelper(Tnode* node){
   if(node == NULL){
    return;
   }else{
    freeTreeHelper(node->left);
    freeTreeHelper(node->right);
    printf("Free Node: %s\n", node->data);
    delete(node);    
   }
}

/** Default constructor for Tnode
 * copy data into constructor variable
*/
Tnode::Tnode(const char* data) {
  this->data = data;
  left = NULL;
  right = NULL;
  count = 1;
}

/** Takes given string (C style) to the left node if the string 
 * comes alphabetically before the string in the current node,
 * or takes it to the right node if  it comes alphabetically 
 * after the string in the current node. After figuring out
 *  child node to go to, it adds a new node with the data if it
 * is NULL, or calls the add function on the child node if it is 
 * not. If the strings are equal, it adds 1 to count in the Tnode.
 * I have decided to make the comparision case sensitive.
 * @param data C style string to add to tree as data
 */
void Tnode::add(const char* data) {
  if(strcmp(this->data, data) > 0){
    if(left == NULL){
      left = new Tnode(data);
    }else{
      left->add(data);
    }
  }else if(strcmp(this->data, data) < 0){
    if(right == NULL){
      right = new Tnode(data);
    }else{
      right->add(data);
    }
  }else{
    count++;
  }
    
}
