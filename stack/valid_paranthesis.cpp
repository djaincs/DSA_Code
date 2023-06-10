//VALID PARANTHESIS:-
#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
	bool ans = true;
	stack<char> st;
	for(int i=0;i<s.length();i++){
		if(s[i] == '(' || s[i] == '{' || s[i] == '['){
			st.push(s[i]);
		}
		else{
			switch(s[i]){
				case ')':
					if(!st.empty() && st.top() == '(')
						st.pop();
					else
						ans = false;	
					break;
				
				case '}':
					if(!st.empty() && st.top() == '{')
						st.pop();
					else
						ans = false;
					break;
				
				case ']':
					if(!st.empty() && st.top() == '[')
						st.pop();
					else
						ans = false;
					break;			
			}
		}
	}
	if(!st.empty())
		return false;
	return ans;
}

int main(){
	
	string s = "({([])})";
	
	if(isValid(s)){
		cout<<"valid string"<<endl;
	}
	else{
		cout<<"Invalid string"<<endl;
	}
	
	return 0;
}
