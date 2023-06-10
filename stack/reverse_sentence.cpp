#include<bits/stdc++.h>
using namespace std;

//Q. Reverse a sentence using stack
void reverse(string s){
	stack<string> st;
	
	for(int i=0;i<s.length();i++){
		string word =" ";
		while(s[i] != ' ' && i<s.length()){
			word += s[i];
			i++;
		}
		st.push(word);
	}
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}cout<<endl;
}

int main(){
	
	string s = "Hey, How are you doing?"; 
	reverse(s);
	
	return 0;
}
