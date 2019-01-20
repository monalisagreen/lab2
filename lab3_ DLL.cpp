#include<iostream>
using namespace std;
class node{
      public:
      //initialisedata
      int data;
      node * next;
      node * prev;
      //constructor to make pointer null 
      node(int val){
	      next=NULL;
	      prev=NULL;
	      data=val;
     }
};

class DoubleLL{
      public:
      //head is first pointer
      node * head;
      //constructor for initial value of head
      DoubleLL(){
       	head=NULL;
      }
      
      //function to add a new element to the end of the list
      void insert(int val){
           //create new node
           node * temp= new Node(data);
           //if list has no elements
           if (head==NULL){
           head=temp;
           }
           //if list has elements
           else {
            node * current = head;
            //loop to move the pointer
            while (current->next!=NULL)
            {
              current=current->next;
            }
            //at last node current's next will be temp
            current->next=temp;
            temp->prev=current;
          }

    }
        
        //function to include the position at which insertion happens
	void insertAt(int pos,int val){
		node * current =head;
		node * temp = new node(val);
		int j=1;
                while(j<pos-1){
                j++;
		current =current->next;
               }
		temp->next=current->next;
		current->next=temp;
		temp->next->prev=temp;
		temp->prev=current;
	}
	
        //deletes the element at the end 
        void delet(){
		node * current=head;
		node * temp ;
		while (current->next->next!=NULL){
		  current=current->next;
		}
		current->next=temp;
		current->next=NULL;
		delete temp;
	}
	
	void deleteAt(int pos){
		node * current =head;
		node * temp ;
		int i=1;
                while(i<pos-1){
                  i++;
		  current =current->next;
                }
		temp=current->next;
		current->next=current->next->next;
		current->next->prev=current;
		delete temp;
	}

        //Count no. of elements 
	void Count(){
		node * current = head;
		int c=1;
		while(current->next!=NULL){
		  c++;
                  current=current->next;
                }
                cout << " Number of elements " << c << endl;}



       void display(){
            node * current=head;           
            node * end;
            cout<<"List in order :";
            while (current!=NULL) {
             cout << current->dt<<"->";
             
             end = current;
             current = current->next;
           }
            cout << endl;
            cout << "List in R order :";
            while(end!=NULL)
            {
              cout << end->data << "->";
              end =end->prev;
            }
            cout << endl;
          
	}

};	



int main(){
    DoubleLL dl1;
    dl1.insert(1);
    dl1.insert(2);
    dl1.insert(3);
    dl1.insert(4);
    dl1.insert(5);
    dl1.display();
    dl1.delet();
    dl1.display();
    dl1.insertAt(4,8);
    dl1.display();
    dl1.deleteAt(3);
    dl1.display();
    dl1.Count();
    
}

