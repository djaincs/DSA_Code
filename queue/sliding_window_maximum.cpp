//sliding window maximum
//we have an array and size of window k and we have to return max of each window of size k.

#include<bits/stdc++.h>
using namespace std;

void win_maximum(vector<int> a,int n,int k){ //TC- O(n*k)
	vector<int> ans;
	for(int i=0;i<=n-3;i++){
		int maxi = a[i];
		for(int j=i;j<=i+k-1;j++){
			maxi = max(maxi,a[j]);
		}
		ans.push_back(maxi);
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}cout<<endl;
}
//optimal solution using deque 
//TC- O(n)+O(n) = O(n)  , SC - O(k)
void optimal_win_max(vector<int> a,int n,int k){
	deque<int> dq; //is holding indexes of greater elements
	vector<int> ans;
	for(int i=0;i<n;i++){
		//remove all out of bounds i.e. indexes out of window eg in 0 1 2 3 for window 1 2 3 index 0 is out of bound
		if(!dq.empty() && dq.front() == i-k)
			dq.pop_front();
		
		//we have to maintain decreaing order in deque so if a[dq.back()] < a[i] we pop from back and current index of a[i]
		//is pushed from back in deque
		while(!dq.empty() && a[dq.back()] < a[i])	
			dq.pop_back();
		dq.push_back(i);
		
		//if window is ended then push_back in ans
		if(i>=k-1){
			ans.push_back(a[dq.front()]);
		}		
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}cout<<endl;
}

int main(){
	int n,k;
	cout<<"enter size of array & size of window";
	cin>>n>>k;
	
	vector<int> a(n);
	
//	for(auto &i:a)
//		cin>>i;    //we can i/p vector by this also
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	win_maximum(a,n,k);
	optimal_win_max(a,n,k);
	
	
	return 0;
}
