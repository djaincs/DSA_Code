//REDUNDANT PARANTHESIS:-
//given a valid mathematical expression,find whether it have redundant paranthesis or not.
//it contain following operators +,-,*,/
//eg:- ((a+b)) -> true  , (a+(a+b)) -> false

#include<bits/stdc++.h>
using namespace std;

void brackets(string s){
	stack<char> st;
	bool ans = false;
	for(int i=0;i<s.length();i++){
		if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
			st.push(s[i]);
	    else if(s[i] == ')'){
	    	if(st.top() == '(')
	    		ans = true;
	    	while(st.top() == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
	    		st.pop();
			}
			st.pop();
		}		
	}
	if(ans)
		cout<<"redundant brackets"<<endl;
	else		
		cout<<"no redundant brackets"<<endl;	
}

int main(){
	string s;
	cout<<"enter expression:-";
	cin>>s;
	
	brackets(s);
	
	return 0;
}
