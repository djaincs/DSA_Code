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

node* reverse_iterative(node* &head){ //TC-O(n)
	node* prev = NULL;
	node* curr = head;
	node* nextptr;
	
	while(curr != NULL){
		nextptr = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextptr;
//nextptr ko aage badane ki jaroorat nhi hai kyuki loop me starting me nextptr=curr->next ho rha hai toh woh apneaap aage badh rha hai
	}
	return prev; //bcoz at the end prev last me hoga & last hamara head ho jaega
}

node* reverse_recursive(node* &head){ //TC- O(n)
	
	if(head==NULL || head->next == NULL)
		return head;
	//recursively call for values after head
	node* newhead = reverse_recursive(head->next);
	//then finally we are left with only head and head->next i.e. starting 2 values
	head->next->next = head; //1->2->3->4->NULL => head->next->next = head means 2->next = head i.e 2->1
	head->next = NULL;
	
	return newhead;
	
}

int main(){
	
	node* head = NULL;
	
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	display(head);
//	node* newhead = reverse_iterative(head);
//	display(newhead);
	node* ans = reverse_recursive(head);
	display(ans);
	
	return 0;
}
