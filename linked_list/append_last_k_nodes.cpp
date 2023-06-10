//APPEND LAST K NODES TO START OF LINKED LIST:-
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

int length(node* head){
	int len = 0;
	node* curr = head;
	while(curr!=NULL){
		len++;
		curr = curr->next;
	}
	return len;
}

node* append_k(node* &head,int k){
	node* tail = head;
	node* newTail;
	node* newHead;
	
	int l = length(head);
	k = k%l; //what if k>l so we do k%l
	int count = 1;
	while(tail->next != NULL){
		if(count == l-k)
			newTail = tail;
		
		if(count == l-k+1)
			newHead =tail;
			
		tail = tail->next;
		count++;		
	}
	newTail->next = NULL;
	tail->next = head;
	
	return newHead;
}

int main(){
	node* head = NULL;
	int arr[] = {1,2,3,4,5,6};
	for(int i=0;i<6;i++){
		insertAtTail(head,arr[i]);
	}
	display(head);
	
	node* ans = append_k(head,2);
	display(ans);
	
	return 0;
}
