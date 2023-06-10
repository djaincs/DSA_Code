#include<bits/stdc++.h>
using namespace std;
#define n 5

template<typename T>

class Stack{
	int top;
	T *a;
	public:
		
		Stack(){
			a = new T[n];
			top = -1;
		}
		
		void push(T val){
			if(top == n-1){
				cout<<"Overflow"<<endl;
				return;
			}
			else{
				top++;
				a[top] = val;
			}
		}
		
		T pop(){
			if(top == -1){
				//cout<<"Underflow"<<endl;
				return 0;
			}
				T item = a[top];
				top--;
			return item;
		}
		
		T peek(){
			if(top == -1){
				//cout<<"Underflow"<<endl;
				return 0;
			}
			return a[top];
		}
		
		bool empty(){
			if(top == -1)
				return true;
			return false;	
		}
};

bool isOperator(char ch){
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return true;
	return false;	
}

int precedency(char ch){
	if(ch == '^')
		return 3;
	else if(ch == '*' || ch == '/')
		return  2;
	else if(ch == '+' || ch == '-')
		return 1;
	return 0;			
}

void intopost(string &in, string &post){
	Stack<char> st;
	int i=0;
	while(i < in.length()){
		if(isOperator(in[i])){
			while(precedency(st.peek()) >= precedency(in[i])){
				post.push_back(st.pop());
			} 
			st.push(in[i]);
		}
		else{
			post.push_back(in[i]);
		}
		i++;
	}
	while(st.peek()){
		post.push_back(st.pop());
	}
}

void str_rev(string &s){
	int len = s.length();
	for(int i=0;i<len/2;i++){
		swap(s[i],s[len-i-1]);
	}
}

void intopre(string &in, string &pre){
	str_rev(in);
	Stack<char> st;
	int i=0;
	while(i < in.length()){
		if(isOperator(in[i])){
			while(precedency(st.peek()) >= precedency(in[i])){
				pre.push_back(st.pop());
			} 
			st.push(in[i]);
		}
		else{
			pre.push_back(in[i]);
		}
		i++;
	}
	while(st.peek()){
		pre.push_back(st.pop());
	}
	str_rev(pre);
}

int solve(int a,char ch,int b){
	if(ch == '+')
		return a+b;
	else if(ch == '-')
		return a-b;	
	else if(ch == '*')
		return a*b;
	else if(ch == '/')
		return a/b;	
	else if(ch == '^')
		return pow(a,b);					
}

int evalpost(string &post){
	Stack<char> st;
	int i=0;
	while(i < post.length()){
		if(isOperator(post[i])){
			int fst,sec;
			sec = st.pop();
			fst = st.pop();
			st.push(solve(fst,post[i],sec));
		}
		else{
			st.push(post[i]-'0');
		}
		i++;
	}
	return st.pop();
}

int evalpre(string &pre){
	Stack<char> st;
	int i=pre.length()-1;
	while(i >=0 ){
		if(isOperator(pre[i])){
			int fst,sec;
			sec = st.pop();
			fst = st.pop();
			//changes from post
			st.push(solve(sec,pre[i],fst));
		}
		else{
			st.push(pre[i]-'0');
		}
		i--;
	}
	return st.pop();
}

int main(){
	string in,post,pre;
	cout<<"enter infix notation:";
	cin>>in;
	intopost(in,post);
	cout<<post<<endl;
	intopre(in,pre);
	cout<<pre<<endl;
	cout<<evalpost(post)<<endl;
	cout<<evalpre(pre);
	
	return 0;
}
