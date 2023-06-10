#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int val){
			data = val;
			next = NULL;
		}
};
class Queue{
	
	Node* front;
	Node* back;
	public:
		
	Queue(){
		front = NULL;
		back = NULL;
	}
	
	void push(int x){	//enqueue
		Node* n = new Node(x);
		if(front == NULL){ //if queue is empty initially
			back = n;
			front = n;
			return;
		}
		
		back->next = n;
		back = n;
	}
	
	void pop(){	//dequeue
		if(front == NULL){
			cout<<"Queue underflow"<<endl;
			return;
		}
		Node* todelete = front;
		front = front->next;
		delete todelete;
	}
	
	int peek(){
		if(front == NULL){
			cout<<"Queue underflow"<<endl;
			return -1;
		}
		return front->data;
	}
	
	bool empty(){
		if(front == NULL){
			return true;
		}
		return false; 
	}
	
};

int main(){
	
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.peek()<<endl;
	q.pop();
	
	cout<<q.empty()<<endl;
}
