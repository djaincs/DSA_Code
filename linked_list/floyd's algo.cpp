//CYCLE DETECTION AND REMOVAL:-

//Floyd's algorithm or hare and tortoise algorithm
//REVERSE K NODES IN LINKED LIST:-
//REVERSE LINKED LIST:-
#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
		node(int val){
			data = val;
			next = NULL;
		}
};

void display(node* head){
	node* curr = head;
	while(curr != NULL){
		cout<<curr->data<<" ";
		curr = curr->next;
	}cout<<endl;
}

void insertAtTail(node* &head,int val){ //head is taken by reference bcoz we have to modify our head
	node* n = new node(val); //creates a node which has its data as val
	node* curr = head;
	if(head == NULL){
		head = n;
		return;
	}
	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = n;
	n->next = NULL;
}

void makeCycle(node* &head,int pos){
	
	node* curr = head;
	node* startnode;
	
	int count = 1;
	while(curr->next != NULL){
		if(count == pos){
			startnode = curr;
		}
		curr = curr->next;		
		count++;
	}
	curr->next = startnode;
}

bool detectCycle(node* head){
	
	node* slow = head;
	node* fast = head;
	
	while(fast != NULL && fast->next != NULL){ //yaha par hum woh condition lagaenge jisme cycle na ho,fast hamara aage chal rha hoga 
	//toh agar fast NULL ke equal ho jata hai mtlb cycle present nhi hogi
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast){
			return true;
		}
	}
	return false;
}

void removeCycle(node* &head){
	
	node* slow = head;
	node* fast = head;
	
	do{
		slow = slow->next;
		fast = fast->next->next;
	}while(slow != fast);

	fast = head;
	while(slow->next != fast->next){
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = NULL;		
}

int main(){
	
	node* head = NULL;
	
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtTail(head,5);
	insertAtTail(head,6);
	display(head);
	
	makeCycle(head,3);
	cout<<detectCycle(head)<<endl;
	removeCycle(head);
	cout<<detectCycle(head)<<endl;
	display(head);
	
	
	return 0;
}
