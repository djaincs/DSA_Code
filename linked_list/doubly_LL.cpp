//DOUBLY LINKED LIST:-
#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node* prev;
		
		node(int val){
			data = val;
			next = NULL;
			prev = NULL;
		}
};

void display(node* head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}cout<<endl;
}

void insertAtHead(node* &head,int val){
	
	node* n = new node(val);
	n->next = head;
	if(head != NULL)
		head->prev = n;
	
	head = n;
}

void insertAtTail(node* &head,int val){
	
	if(head == NULL){
		insertAtHead(head,val);
		return;
	}
	node* n = new node(val);
	node* curr = head;
	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = n;
	n->prev = curr;
}

void deleteAtHead(node* &head){
	node* todelete = head;
	head = head->next;
	head->prev = NULL;
	
	delete todelete;
}

void deletion(node* &head,int pos){
	
	if(pos == 1){
		deleteAtHead(head);
		return;
	}
	
	node* curr = head;
	int count = 1;
	
	while(curr != NULL && count != pos){		
		curr = curr->next;
		count++;
	}

	curr->prev->next = curr->next;
	
	if(curr->next != NULL)
		curr->next->prev = curr->prev;
		
	delete curr;
}

int main(){
	
	node* head = NULL;
	
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtTail(head,5);
	display(head);
	insertAtHead(head,6);
	display(head);
	deletion(head,3);
	display(head);
	deletion(head,1);
	display(head);
	
	return 0;
}
