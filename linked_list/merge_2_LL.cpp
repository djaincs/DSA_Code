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

node* merge(node* &head1,node* &head2){
	node* ptr1 = head1;
	node* ptr2 = head2;
	node* ansNode = new node(-1);
	node* ptr3 = ansNode;
	
	while(ptr1 != NULL &&  ptr2 != NULL){
		if(ptr1->data < ptr2->data){
			ptr3->next = ptr1;
			ptr1 = ptr1->next;
		}
		else{
			ptr3->next = ptr2;
			ptr2 = ptr2->next;
		}
		ptr3 = ptr3->next;
	}
	while(ptr1 != NULL){
		ptr3->next = ptr1;
		ptr1 = ptr1->next;
		ptr3 = ptr3->next;
	}
	while(ptr2 != NULL){
		ptr3->next = ptr2;
		ptr2 = ptr2->next;
		ptr3 = ptr3->next;
	}
	return ansNode->next; //as starting node is -1
}

node* mergeRecursive(node* &head1,node* &head2){
	
	if(head1 == NULL)
		return head2;
	
	if(head2 == NULL)
		return head1;	
	
	node* ans;
	if(head1->data < head2->data){
		ans = head1;
		ans->next = mergeRecursive(head1->next,head2);
	}
	else{
		ans = head2;
		ans->next = mergeRecursive(head1,head2->next);
	}
	return ans;
}

int main(){
	node* head1 = NULL;
	node* head2 = NULL;
	int a1[] = {1,4,5,5,7};
	int a2[] = {2,3,6};
	int s1 = sizeof(a1)/sizeof(0);
	int s2 = sizeof(a2)/sizeof(0);
	for(int i=0;i<s1;i++){
		insertAtTail(head1,a1[i]);
	}
	for(int i=0;i<s2;i++){
		insertAtTail(head2,a2[i]);
	}
	display(head1);
	display(head2);
//	node* ans = merge(head1,head2);
//	display(ans);
	node* res = mergeRecursive(head1,head2);
	display(res);
	
	return 0;
}
