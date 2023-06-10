#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node* next; //node* type bcoz it is storing address of next node
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

void insertAtHead(node* &head,int val){
	node* n = new node(val); //creates a node which has its data as val
	n->next = head;
	head = n;
}

bool search(node* head,int val){
	node* curr = head;
	
	while(curr != NULL){
		if(curr->data == val)
			return true;
		curr = curr->next;		
	}
	return false;	
}

void deleteAtHead(node* &head){
	
	node* todelete = head;
	head = head->next;
	delete todelete;
}

void deletion(node* &head,int val){
	
	if(head == NULL)
		return;
		
	if(head->next == NULL || head->data == val){
		deleteAtHead(head);
		return;
	}
	
	node* curr = head;
	while(curr->next->data != val && curr->next!=NULL){
		curr = curr->next;
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
	insertAtHead(head,4);
	display(head);
	cout<<search(head,5);
	cout<<endl;
	deletion(head,2);
	display(head);
	
	return 0;
}
