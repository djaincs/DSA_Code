//PUT EVEN POSITION ELEMENTS AFTER ODD POSITION ELEMENTS IN LL:-
//MERGE 2 SORTED LINKED LISTS:-
//TC- O(n+m)
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
		cout<<curr->data<<"->";
		curr = curr->next;
	}cout<<"NULL"<<endl;
}

void insertAtTail(node* &head,int val){
	
	node* n = new node(val);
	node* curr = head;
	if(head==NULL){
		head = n;
		return;
	}
	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = n;
}

void evenAfterOdd(node* &head){
	node* odd = head;
	node* even = head->next;
	node* evenStart = even;
	
	while(odd->next != NULL && even->next != NULL){
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = evenStart;
	if(odd->next != NULL){
		even->next = NULL;
	}
}



int main(){
	node* head = NULL;
	
	int a[] = {1,2,7,4,5,6};

	int s1 = sizeof(a)/sizeof(0);
	for(int i=0;i<s1;i++){
		insertAtTail(head,a[i]);
	}
	
	display(head);
	evenAfterOdd(head);
	display(head);
	
	
	return 0;
}

