//TRAPPING RAINWATER HARVESTING:-
//given non -ve integers array representing an elevation map where the width of each bar is 1, (ith element->ith bar height)
//compute how much water it can trap after raining.
#include<bits/stdc++.h>
using namespace std;

int rainwater(vector<int> a){
	stack<int> st;
	int n=a.size(),ans=0;
	for(int i=0;i<n;i++){
		while(!st.empty() && a[st.top()] < a[i]){ //if condition holds water will store in that area
			int curr = st.top();
			st.pop();
			
			if(st.empty()){ //that means there is no supporting bar in lhs so we simply break
				break;
			}
			int diff = i - st.top() -1; //length or width of container
			ans += (min(a[st.top()],a[i])-a[curr])*diff; //a[st.top()] and a[i] are walls of container where a[st.top()]
			//is left wall and a[i] is right wall and if we subtract a[curr] from it we get the height of container
		}
		st.push(i);
	}
	return ans;	
}

int main(){
	vector<int> a={0,1,0,2,1,0,1,3,2,1,2,1};
	cout<<rainwater(a);
	
	return 0;
}
