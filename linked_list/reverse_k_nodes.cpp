//REVERSE K NODES IN LINKED LIST:-
//1->2->3->4->5->6->NULL,k=2 => 2->1->4->3->6->5->NULL
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

node* reverse_k(node* &head,int k){ //TC- O(n)
	
	node* prev = NULL;
	node* curr = head;
	node* nextptr;
	int count=0;
	
	while(curr != NULL && count<k){
		nextptr = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextptr;
		
		count++;
	}
	if(nextptr != NULL)
		head->next = reverse_k(nextptr,k); //let k=2, we are storing in head->next bcoz in 1->2->3->4->NULL when we reverse  1->2 then we get
	//2->1 and head is on 1 and we have to connect 1->4 so that it becomes 1->2->4->3->NULL so we store in head->next
	
	return prev;	
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
	int k=2;
	
	node* ans = reverse_k(head,k);
	display(ans);

	
	return 0;
}
