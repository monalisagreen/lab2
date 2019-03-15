#include<iostream>
using namespace std;

class Node{
public:
    //class variables
    int data;
    Node * l;
    Node * r;

    Node(int value){
        data = value;
        l = NULL;
        r = NULL;
    }  
};

class BST{
public:
    Node * root;
    //constructor
    BST(){
        root = NULL;
    }
    void insertHelper(int value){
        insert(root, value);
    }
    void insert(Node *curr, int value){
         
        if (root == NULL) {
            root = new Node(value);
        }
         
        
        else if (value < curr->data)  {
             
            if (curr->l == NULL) curr->l = new Node(value);
            
            else insert(curr->l, value);
        }
        else {
             
            if (curr->r == NULL) curr->r = new Node(value);
            
            else insert(curr->r, value);
        }
    }
    //display tree elements
    void displayHelper(){
        display(root);
    }
    void display(Node * curr){
        // Case for empty tree and leaf nodes children.
        if( curr ==  NULL) return;
        // IN order print.
        // Print left. 
        display(curr->l);
        // Print myself.
        cout << curr->data << ", ";
        // Print right.
        display(curr->r);
    }
    Node * searchHelper(int value){
        return search(root, value);
    }
    Node * search(Node * curr, int value){
        // Are you the value? or Are you NULL?  if yes return curr
        if(curr == NULL || curr->data == value ) return curr;
        // else you search in right or left. 
        // Left
        else if(value < curr->data) return search(curr->l, value);
        // Right
        else  return search(curr->r, value);
    }

};

int main(){
    BST bst1;
    bst1.insertHelper(4);
    bst1.insertHelper(2);
    bst1.insertHelper(1);
    bst1.insertHelper(3);
    bst1.insertHelper(5);
    bst1.displayHelper();
    if(bst1.searchHelper(3) != NULL){
        cout << endl << bst1.searchHelper(3)->data << endl;
    }
}
