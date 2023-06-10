#include<bits/stdc++.h>
using namespace std;

//given an array having n elements and key, we have to find 1st and last occurence of k
//for sorted array
int firstOcc(vector<int> a,int n,int key){
	int l = 0,h = n-1,ans = -1;
	while(l<=h){
		int mid = l+(h-l)/2;
		if(a[mid] == key){
			ans = mid;
			h = mid-1;
		}	
		else if(a[mid]<key)
			l = mid+1;
		else
			h = mid-1;		
	}
	return ans;
}

int lastOcc(vector<int> a,int n,int key){
	int l = 0,h = n-1,ans = -1;
	while(l<=h){
		int mid = l+(h-l)/2;
		if(a[mid] == key){
			ans = mid;
			l = mid+1;
		}	
		else if(a[mid]<key)
			l = mid+1;
		else
			h = mid-1;		
	}
	return ans;
}

pair<int,int> firstAndlastPosition(vector<int> a,int n,int key){
	pair<int,int> ans;
	ans.first = firstOcc(a,n,key);
	ans.second = lastOcc(a,n,key);
	return ans;
}



int main(){
	
	int t;
	cout<<"testcases:";
	cin>>t;
	
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> a(n);
		for(int i=0;i<n;i++) 
			cin>>a[i];
			
		pair<int,int> ans;
		ans = firstAndlastPosition(a,n,k);
		cout<<"First occurence:"<<ans.first<<endl;
		cout<<"Last occurence:"<<ans.second<<endl;
		cout<<"Total occurences:"<<ans.second+ans.first-1<<endl;
	}
	
	
	
	return 0;
}
