//LARGEST RECTANGLE IN A HISTOGRAM:-
//given an array.each element represent the height of histogram's bar and the width of each bar is 1,find area of largest
//rectangle in histogram.

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE:-
void largest_rect(vector<int> a,int n){
	int ans = 0;
	for(int i=0;i<n;i++){
		int mini = INT_MAX; //for height
		for(int j=i;j<n;j++){
			mini = min(mini,a[j]);
			int width = j-i+1;
			ans = max(ans,width*mini);
		}
	}
	cout<<ans<<endl;
}

//OPTIMAL APPROACH USING STACK
void get_max_area(vector<int> a,int n){
	stack<int> st;
	int ans = 0,i=0;
	a.push_back(0); //so that last bar is 0 and we don't need to handle it separately in stack
	while(i<n){
		while(!st.empty() && a[st.top()] > a[i]){
			int height = a[st.top()];
			st.pop();
			if(st.empty()){
				ans = max(ans,height*i);
			}
			else{
				int len = i-st.top()-1;
				ans = max(ans,height*len);
			}
		}
		st.push(i);
		i++;
	}
	cout<<ans<<endl;
}

int main(){
	
	int n;
	cout<<"enter size of array:-";
	cin>>n;
	
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	largest_rect(a,n);
	get_max_area(a,n);
	
	return 0;
}
