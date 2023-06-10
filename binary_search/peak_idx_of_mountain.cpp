#include<bits/stdc++.h>
using namespace std;

//Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
//You must solve it in O(log(arr.length)) time complexity.
int peakIndexInMountainArray(vector<int>& arr) {
    int start = 0,end = arr.size()-1;
    while(start<end){
    int mid = start+(end-start)/2;
    	if(arr[mid]<arr[mid+1])
       		start = mid+1;
       	else
			end = mid;	
	}
	return start;
}


int main(){
	
	int t;
	cout<<"testcases:";
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++) 
			cin>>a[i];
			
		cout<<"Peak of mountain is:"<<peakIndexInMountainArray(a);
	}
	
	
	
	return 0;
}
