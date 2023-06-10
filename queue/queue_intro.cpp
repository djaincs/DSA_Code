//QUEUE:-
//stores a list of items in which an item can be added or inserted from one end & removed from other end  only.
//based on FIFO mechanism
//operations :- enqueue(x),dequeue(),peek(),empty()
//inserted from back or rear and removed from front end

#include<bits/stdc++.h>
using namespace std;
#define n 20
class Queue{
	
	int *arr;
	int front;
	int back;
	public:
		
	Queue(){
		arr = new int[n];
		front = -1;
		back = -1;
	}
	
	void push(int x){	//enqueue
		if(back == n-1){
			cout<<"Queue overflow"<<endl;
			return;
		}
		back++;
		arr[back] = x;
		
		if(front == -1)
			front++;
	}
	
	void pop(){	//dequeue
		if(front == -1 || front > back){	//front>back means element remove karte karte hum back ko cross karde
		// means hamari queue empty hai
			cout<<"Queue underflow"<<endl;
			return;
		}
		front++;
	}
	
	int peek(){
		if(front == -1 || front > back){	
			cout<<"Queue underflow"<<endl;
			return -1;
		}
		return arr[front];
	}
	
	bool empty(){
		if(front == -1 || front > back){	
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
