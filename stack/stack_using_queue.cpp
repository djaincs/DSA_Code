//stack using queue
//2 methods:-
//1. making push method costly
//2. making pop method costly
#include<bits/stdc++.h>
using namespace std;

class Stack{
	//method 1
	
	int n; //size
	queue<int> q1;
	queue<int> q2;
	
	public:
		Stack(){
			n=0;
		}
		
		void push(int x){
			q2.push(x);
			n++;
			while(!q1.empty()){
				q2.push(q1.front());
				q1.pop(); //pop element which is pushed in q2
			}
			//swap q1 and q2
			queue<int> temp = q1;
			q1 = q2;
			q2 = temp;
		}
		
		void pop(){
			if(q1.empty()){
				cout<<"stack underflow"<<endl;
				return;
			}
			q1.pop();
			n--;
		} 
		
		int top(){
			if(q1.empty()){
				cout<<"stack underflow"<<endl;
				return -1;
			}
			return q1.front();
		}
		
		int size(){
			return n;
		}
		
};

class Stack2{
	//method 2
	
	int n; //size
	queue<int> q1;
	queue<int> q2;
	
	public:
		Stack2(){
			n=0;
		}
		
		void push(int x){
			q1.push(x);
			n++;
		}
		
		void pop(){
			if(q1.empty()){
				cout<<"stack underflow"<<endl;
				return;
			}
			while(q1.size() != 1){
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop(); //final element in q1 is popped as stack follows lifo & element which is inserted 
			//last in queue will be popped according to lifo
			n--;
			
			//swap q1 and q2
			queue<int> temp = q1;
			q1 = q2;
			q2 = temp;
		} 
		
		int top(){
			if(q1.empty()){
				cout<<"stack underflow"<<endl;
				return -1;
			}
			while(q1.size() != 1){
				q2.push(q1.front());
				q1.pop();
			}
			int topval = q1.front();
			q2.push(topval);
			
			//swap q1 and q2
			queue<int> temp = q1;
			q1 = q2;
			q2 = temp;
			
			return topval;
		}
		
		int size(){
			return n;
		}
		
};

int main(){
	
	Stack2 s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	
	cout<<s.size()<<endl;
	
	
	return 0;
}
