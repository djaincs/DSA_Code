#include<bits/stdc++.h>
using namespace std;

//Q. infix to postfix expression 


// if operand
//print
//if "("
//push to stack
//if ")"
//pop from stack and print until "(" is found 
//if operator
//pop from stack and print util an operator with less precedence is found


int precedence(char c){
	if(c == '^')
		return 3;
	else if(c == '*' || c == '/')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else 
		return -1;			
}

string convert(string s){
	
	
	
	stack<char> st;
	string res;
	
	for(int i=0;i<s.length();i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
			res += s[i];
			
		else if(s[i] == '(')
			st.push(s[i]);
			
		else if(s[i] == ')'){
			while(!st.empty() && st.top() != '('){
				res += st.top();
				st.pop();
			}
			//finally pop '(" from stack
			if(!st.empty())
				st.pop();
		}
		
		else{
			while(!st.empty() && precedence(st.top()) >= precedence(s[i])){
				res += st.top();
				st.pop();
			}
			//finally push current operator i.e. less precedence operator
			st.push(s[i]);
		}
				
	}
	//check if anything left in stack if yes then add it in res
		while(!st.empty()){
			res += st.top();
			st.pop();
		}
		
		
		
	return res;
	
}

int main(){
	
	string s = "(a-b/c)*(a/k-l)";
	cout<<convert(s)<<endl; 
	
	return 0;
}
