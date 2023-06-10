//STOCK SPAN PROBLEM:-
//the span of stock's price today is defined as max no. of consecutive days (starting from today & going backwards)
//for which the price of stocks was <= today's price. find span of stocks for all days.
//eg:- Array = [100,80,60,70,60,75,85]
//ans = [1,1,1,2,1,4,6]
//100 80 60 70 60 75 85
#include<bits/stdc++.h>
using namespace std;
//BRUTE FORCE:-

void stock(vector<int> a,int n){
	vector<int> ans(n);
	
	// Span value of first day is always 1
	ans[0] = 1;
	for(int i=1;i<n;i++){
		 ans[i]=1;
		for(int j=i-1;j>=0;j--){
			if(a[i] >= a[j]){
				ans[i]++;
			}
			else{ 
				break; //bcoz we need consecutive small values
			}
		}
	}
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}cout<<endl;
}

//OPTIMIZED:-
//create a stack<pair<int,int>> representing {price,days}
vector<int> stock_span(vector<int> prices){
	vector<int> ans;
	stack<pair<int,int>> st;
	
	for(auto i:prices){
		int days = 1;
		while(!st.empty() && st.top().first <= i){
			days += st.top().second;
			st.pop(); //after adding days pop from stack
		}
		st.push({i,days}); //push current price and total days
		ans.push_back(days);
	}
	
	return ans;
}

int main(){
	int n;
	cout<<"enter size of array:-";
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	//stock(a,n);
	vector<int> res = stock_span(a);
	for(auto i:res){
		cout<<i<<" ";
	}cout<<endl;
	
	return 0;
}
