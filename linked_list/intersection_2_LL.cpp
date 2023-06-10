//FIND INTERSECTION POINTS OF 2 LINKED LIST:-
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

int length(node* head){
	int l=0;
	node* curr = head;
	while(curr != NULL){
		curr = curr->next;
		l++;
	}
	return l;
}

void intersect(node* &head1,node* &head2,int pos){
	//here we are adding head2 at end of head1
	node* a = head1;
	node* b = head2;
	pos--;
	while(pos--){
		a = a->next;
	}
	while(b->next != NULL){
		b= b->next;
	}
	b->next = a;
}

int intersection(node* head1,node* head2){
	int len1 = length(head1);
	int len2 = length(head2);
	int diff=0;
	node* a;
	node* b;
	if(len1 > len2){
		a = head1;
		b = head2;
		diff = len1-len2;
	}
	else{
		a = head2;
		b = head1;
		diff = len2-len1;
	}
	while(diff != 0){
		a = a->next;
		if(a == NULL){
			return -1;
		}
		diff--;
	}

	while(a!=NULL && b!= NULL){
		
		if(a == b){
			return a->data;
		}
		a = a->next;
		b = b->next;
	}
	return -1;
}

int main(){
	
	node* head1 = NULL;
	node* head2 = NULL;
	
	insertAtTail(head1,1);
	insertAtTail(head1,2);
	insertAtTail(head1,3);
	insertAtTail(head1,4);
	insertAtTail(head1,5);
	insertAtTail(head1,6);
	insertAtTail(head2,9);
	insertAtTail(head2,10);
	insertAtTail(head2,8);
	intersect(head1,head2,3);
	display(head1);
	display(head2);
	
	cout<<intersection(head1,head2)<<endl;
	
	return 0;
}
