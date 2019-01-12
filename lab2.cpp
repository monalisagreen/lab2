#include<iostream>
using namespace std;

class Node {
     public:
     //Data
     int val;
     //Pointer to the next Node
     Node * next;
     //Constructor that makes ptr to NULL
     Node() {
       next = NULL;
     }
};

class LinkedList{
     //Head+Circles inside linked with each other
     public:
     //Head -> Node type ptr
     Node * head;
     Node * tail;
     //Construct
     LinkedList() {
       head = NULL;
       tail = NULL;
     }

     //Insert
     void insert(int data) {
       //If 1st node is added
       Node * temp = new Node;
       //Insert value in the node
       temp->val = data;
       //1st node only
       if(head == NULL) {
         head = temp;
       }
       //Any other node only 
       else {
         tail->next = temp;
       }
       tail = temp;
     }
     
     void insertAt(int pos, int data) {
       //Reach the place before the position
       Node * current = head;
       int i=1;
       while (i < pos-1) {
         i++;
         current = current->next;
       }
       //Create a node
       Node * temp = new Node;
       temp -> val = data;
       
       temp->next = current->next;
       current->next = temp;
       
       if(i>pos) {
         cout << "Linked list does not have that many elements" << endl;
       }
     }
     //Delete the element at the end of the list
     void delet() {
       //store the tail in temp
       Node * temp = tail;
       //before tail has to point to null
       Node * current = head;
       while(current->next != tail) {
         current= current->next;
       }
       current->next = NULL;
       
       //update tail
       tail = current;
       //delete temp
       delete temp;
     }
     //delete the element at the position pos
     void deleteAt(int pos) {
       //if linked list is empty
       if(head== NULL) {
         return ; }
       Node * temp= head;
       if(pos == 0) {
         head= temp-> next;
         return ;
         }
       for(int i=0;temp != NULL && i<pos-1; i++ ) {
         temp= temp->next;
       }
       //if position is more than number of nodes
       if(temp==NULL || temp->next== NULL)
       return ;
       //Pointer to the next of the node to be deleted
       Node * next= temp->next->next;
       temp->next= next;
     }
     //return the number of iteams in link list
     int countItems() {
       int num =0;
       Node * current = head;
       while(current != NULL) {
         num++;
         current= current->next;
       }
       return num;
     }
     //Display
     void display() {
       Node * current = head;
       while(current != NULL) {
         cout << current->val << "->";
         current= current->next;
       }
       cout << endl;
     }

};

int main() {
     LinkedList l1;
     l1.insert(1);
     l1.insert(2);
     l1.insert(3);
     l1.insert(4);
     l1.display();
     l1.delet();
     l1.display();
     l1.insertAt(1,5);
     l1.display();
     l1.deleteAt(3);
     l1.display();
     cout << "The number of items in linked list is= " << l1.countItems() << endl; 
     return 0;
}

