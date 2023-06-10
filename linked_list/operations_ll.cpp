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

class linked_list{
	public:
		void print_LL(node* head){
			while(head!=NULL){
				cout<<head->data<<" ";
				head = head->next;
			}
			cout<<endl;
		}
		
		void insertAtHead(node* &head, int val){
			node* newNode = new node(val);
			newNode->next = head;
			head = newNode;
		}
		
		void insertAtTail(node* &head, int val){
			node* n = new node(val);
			node* curr = head;
			if(head == NULL){
				head = n;
				return;
			}
			while(curr->next != NULL){
				curr = curr->next;
			}
			curr->next = n;	
		}
		
		void insertAtPos(node* &head, int val,int pos){
			node* n = new node(val);
			node* curr = head;
			if(pos == 0){
				insertAtHead(head,val);
				return;
			}
			int cn = 0;
			while(curr->next != NULL && cn != pos-1){
				curr = curr->next;
				cn++;
			}
			n->next = curr->next;
			curr->next = n;
		}
		
		void insertbefore(node* &head, int val, int key){
			node* n = new node(val);
			node* curr = head;
			if(curr->data == key){
				insertAtHead(head,val);
				return;
			}
			while(curr->next != NULL && curr->next->data != key){
				curr = curr->next;
			}
			n->next = curr->next;
			curr->next = n;
		}
		
		void insertafter(node* &head, int val, int key){
			node* n = new node(val);
			node* curr = head;
			
			while(curr->next != NULL && curr->data != key){
				curr = curr->next;
			}
			n->next = curr->next;
			curr->next = n;
		}
		
		void deletehead(node* &head){
			node* todelete = head;
			head = head->next;
			delete todelete;
		}
		
		void deletetail(node* &head){
			node* curr = head;
			while(curr->next->next != NULL){
				curr = curr->next;
			}
			node* todelete = curr->next;
			curr->next = NULL;
			delete todelete;
		}
		
		void deleteval(node* &head,int val){
			node* curr = head;
			if(curr->data == val){
				deletehead(head);
				return;
			}
			while(curr->next != NULL && curr->next->data != val){
				curr = curr->next;
			}
			node* todelete = curr->next;
			curr->next = curr->next->next;
			delete todelete;
		}
		
};

int main(){
	node* head = NULL;
	linked_list l;
	l.insertAtHead(head,10);
	l.insertAtHead(head,20);
	l.insertAtTail(head,30);
	l.insertAtPos(head,40,2);
	l.insertAtPos(head,50,1);
	l.insertbefore(head,60,50);
	l.insertafter(head,70,20);
	
	l.print_LL(head);
	
	l.deletehead(head);
	l.deletetail(head);
	l.deleteval(head,10);
	
	l.print_LL(head);
}

