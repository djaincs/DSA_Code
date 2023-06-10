//MERGE SORT:-

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int st, int mid, int end){
	
	const int sub1 = mid-st+1;
	const int sub2 = end-mid;
	
	vector<int> leftarr(sub1);
	vector<int> rightarr(sub2);
	
	//copying elements to subarrays
	for(int i=0;i<sub1;i++)
		leftarr[i] = a[st+i];
	for(int i=0;i<sub2;i++)
		rightarr[i] = a[mid+1+i];
	
	int idx1=0,  // Initial index of first sub-array
	idx2=0,	// Initial index of second sub-array
	idxm=st;		// Initial index of merged array
	
	while(idx1 < sub1 && idx2 < sub2){
		if(leftarr[idx1] <= rightarr[idx2]){
			a[idxm] = leftarr[idx1];
			idx1++;
		}
		else{
			a[idxm] = rightarr[idx2];
			idx2++;
		}
		idxm++;
	}
	
	// Copy the remaining elements of
    // left[], if there are any
    while(idx1 < sub1){
    	a[idxm] = leftarr[idx1];
    	idx1++;
    	idxm++;
	}
	
	// Copy the remaining elements of
    // right[], if there are any
    while(idx2 < sub2){
    	a[idxm] = rightarr[idx2];
    	idx2++;
    	idxm++;
	}
}

void merge_sort(vector<int> &a, int st, int end){
	if(st >= end)	
		return;
	int mid = st + (end-st)/2;
	
	merge_sort(a,st,mid);
	merge_sort(a,mid+1,end);
	merge(a,st,mid,end);	
}

int main(){
	int n;
	cout<<"enter no. of elements:";
	cin>>n;
	vector<int> a(n);
	cout<<"enter elements of array:";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"elemens of array are:"<<"\t";
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	merge_sort(a,0,n-1);
	cout<<"after sorting elemens of array are:";
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
}
