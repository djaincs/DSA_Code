//Given a sorted and rotated array arr[] of size N and a key, the task is to find the key in the array.
//Note: Find the element in O(logN) time and assume that all the elements are distinct.
//Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}, key = 3
//Output : Found at index 8

#include<bits/stdc++.h>
using namespace std;

int bin_search(vector<int> a,int key,int st,int end ){
	if(st > end)
		return -1;
	
		int mid = st+(end-st)/2;
		if(a[mid] == key)
			return mid;
			
		if(a[mid] > key)
			return bin_search(a,key,st,mid-1);
		return bin_search(a,key,mid+1,end);	
}

int find_pivot(vector<int> a,int st, int end){
	
	if(st > end)
		return -1;
	if(st == end)
		return st;	
	
	int mid = st+(end-st)/2;
	
	if(mid < end && a[mid] > a[mid+1])
		return mid;
	
	if(mid > st && a[mid] < a[mid-1])
		return (mid-1);
	
	if(a[st] >= a[mid])
		return find_pivot(a,st,mid-1);	
	return find_pivot(a,mid+1,end);		
}

//Another method of finding pivot
int get_pivot(vector<int> a,int st, int end){
	int mid;
	while(st < end){
		mid = st+(end-st)/2;
		if(a[mid] >= a[st])
			st = mid+1;
		else
			end = mid-1;	
	}
	return st;
}

int rotate_bin_search(vector<int> a,int n,int key){
	int pivot = get_pivot(a,0,n-1);
	// If we didn't find a pivot, then array is not rotated at all
	if(pivot == -1)
		return bin_search(a,key,0,n-1);
	
	// If we found a pivot, then first compare with pivot
    // and then search in two subarrays around pivot
	if(a[pivot]==key)
		return pivot;
	
	if(a[0] <= key && key <=a [pivot])
		return bin_search(a,key,0,pivot-1);
	return bin_search(a,key,pivot+1,n-1);		
}

int main(){
	
	vector<int> a = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	int n = a.size();
	int key = 1;
	int st=0, end = n-1;
	
	cout<<"index of element is:"<<rotate_bin_search(a,n,key);
	
	return 0;
}
