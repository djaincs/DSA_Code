//STACK:-
//stores a list of items in which an item can be added or removed from the list only at one end.
//based on LIFO mechanism
//operations :- push(x),pop(),top(),empty()

#include<bits/stdc++.h>
using namespace std;
#define n 100

class Stack{
	
	int *arr;
	int top;
	public:
		Stack(){
			//allocate dynamic memory to array
			arr = new int[n];
			top = -1;
		}
		
		void push(int x){
			if(top == n-1){
				cout<<"Stack overflow"<<endl;
				return;
			}
			else{
				top++;
				arr[top] = x;
			}
		}
		
		void pop(){
			if(top == -1){
				cout<<"Stack underflow"<<endl;
				return;
			}
			else{
				top--;
			}
		} 
		
		int Top(){
			if(top == -1){
				cout<<"Stack underflow"<<endl;
				return -1;
			}
			return arr[top];
		}
		
		bool empty(){
			if(top == -1)
				return true;
			return false;	
		}
		
};

int main(){
	
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout<<s.Top()<<endl;
	s.pop();
	cout<<s.Top()<<endl;
	s.pop();
	s.pop();
	s.pop();
	cout<<s.empty()<<endl;
	
	
	return 0;
}
