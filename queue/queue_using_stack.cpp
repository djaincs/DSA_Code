#include<bits/stdc++.h>
using namespace std;
#define n 20
class Queue{
	stack<int> s1;
	stack<int> s2;
	public:
	void push(int x){	//enqueue
		s1.push(x);
	}
	
	int pop(){	//dequeue
		if(s1.empty() && s2.empty()){
			cout<<"queue is empty"<<endl;
			return -1;
		}
		if(s2.empty()){
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}
		int topval = s2.top();
		s2.pop();
		return topval;  //peek value
		 
	}

	bool empty(){
		if(s1.empty() && s2.empty()){
			return true;
		}
		return false; 
	}
	
};

class Queue2{
	//using only 1 stack
	stack<int> s1;
	
	public:
	void push(int x){	//enqueue
		s1.push(x);
	}
	
	int pop(){	//dequeue
		if(s1.empty()){
			cout<<"queue is empty"<<endl;
			return -1;
		}
		int x = s1.top();
		s1.pop();
		if(s1.empty()){ //now if s1.empty then only 1 element is there in stack so we return x which we have already stored
			return x;
		}
		//recursively call pop() funcion till end of stack and then push them in s1
		int item = pop();
		s1.push(x);
		return item;  
		 
	}

	bool empty(){
		if(s1.empty()){
			return true;
		}
		return false; 
	}
};

int main(){
	
	Queue2 q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout<<q.pop()<<endl;
	q.push(5);
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	
	cout<<q.empty()<<endl;
}
