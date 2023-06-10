//CIRCULAR LINKED LIST:-
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
	do{
		cout<<curr->data<<" ";
		curr = curr->next;
	}while(curr != head);
	cout<<endl;
}

void insertAtHead(node* &head,int val){
	node* n = new node(val);
	node* curr = head;
	
	if(head == NULL){
		n->next = n;
		head = n;
		return;
	}
	
	while(curr->next != head){
		curr = curr->next;
	}
	curr->next = n;
	n->next = head;
	head = n;
}

void insertAtTail(node* &head,int val){
	if(head == NULL){
		insertAtHead(head,val);
		return;
	}
	
	node* n = new node(val);
	node* curr = head;
	
	while(curr->next != head){
		curr = curr->next;
	}
	curr->next = n;
	n->next = head;
}

void deleteAtHead(node* &head){
	node* curr = head;
	node* todelete = head;
	while(curr->next != head){
		curr = curr->next;
	}
	
	curr->next = head->next;
	head = head->next;
	delete todelete;
}

void deletion(node* &head,int pos){
	
	if(pos==1){
		deleteAtHead(head);
		return; 
	}
	
	node* curr = head;
	int count=1;
	while( count != pos-1){
		curr = curr->next;
		count++;
	}
	node* todelete = curr->next;
	curr->next = curr->next->next;
	delete todelete;
	
}

int main(){
	
	node* head = NULL;
	
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	display(head);
	insertAtHead(head,5);
	display(head);
	
	deletion(head,1);
	display(head);
	deletion(head,4);
	display(head);
	
	return 0;
}
