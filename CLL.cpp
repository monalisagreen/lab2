#include<iostream>
using namespace std;
					

class Node{
	public:
	//data and ptr to next node				
	int data;
	Node * next;
	//making constructor to point to null 				
	Node(){
		next=NULL;
		
		
	}
};
//make class of circular linked list
class CLL {
	public:
	//point to head
	Node * head;
	Node * tail;
	//constructor to make it point to null
	CLL(){
		head=NULL;
		tail=head;
	}

//for inserting a new node at the end of the list
void insert(int value){
	//creating a new node
	Node*temp=new Node;
	temp->data=value;
	//checking if the list is empty
	if(head==NULL){
		head=temp;
	}
	//if the list is not empty
	else{
		Node*current=head;
		while(current->next!=head)
			current=current->next;
		current->next=temp;
	}
	//pointing the last node to head to make it circular
	temp->next=head;
}
	//inserting a node at a particular position
void insertAt(int pos,int value){
	//ptr to head
	Node * current=head;
	
	//creating a loop to reach the (pos-1)th node
	int i=1;
	while(i<pos-1){
	  i++;
	current=current->next;
	}
	//creating a new node
	Node*temp=new Node;
	temp->data=value;
	//establishing the link by moving the pointers
	temp->next=current->next;
	current->next=temp;
}
//deleting the last node 
void delet(){
	//ptr to the head and tail
	Node*curr=head;
	Node*temp1=tail;
	//making a loop to reach the last node
	int i=1;
	while(curr->next!=tail){
		curr=curr->next;
	}
	//the tail should point to null
	curr->next->next=NULL;
	//the current last node should point to head
	curr->next=head;
	//update the tail
	tail=curr;
	//delete the tail
	delete temp1;
	}
	//delete at a particular position
void deletAt(int pos){
	//ptr to head
	Node*temp=head;
	if(pos==1){
		head=temp->next;
		delete temp;
	return;
	}
	//if pos is not 1
	

					
        //making a loop to reach the (pos-1)th node
	for(int i=1;i<pos-1;i++){
		temp=temp->next;
	}
        //pointer to the node that has to be deleted
	Node*temp1=temp->next;
	//moving the ptrs
	temp->next=temp1->next;
	//deleting the node
	delete temp1;
}
	//countitems
int countItems(){
	//ptr to the head
	Node*temp2=head;
	//loop to cover all the elements of the list
	int j=0;
	while(temp2!=NULL){
		j++;
		temp2=temp2->next;
	}
	return j;
}
//displays the elements of the list
 void display(){
        Node * current = head;
        if(current == NULL) {
            cout << "No elements " << endl;
            return;
        }
        while(current->next != head){ // Stopping at head
            cout << current -> data << "->";
            current = current -> next;
        }
        // Printing the last element
        cout << current -> data ;
        cout << endl;
    }
};

int main(){
		CLL cll;
	for(int i= 1; i < 11; i++){
		cll.insert(i);
    }

		cll.display();
		cll.insertAt(5,2);
		cll.display();
		cll.delet();
		cll.display();
		cll.deletAt(7);
		cll.display();
		cout<<"the number of items is:"<<cll.countItems()<<endl;

	
}	
			
				

	
	
	
	

	
	
	


