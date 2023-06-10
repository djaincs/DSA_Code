//TC:- O(log n)
//Best Case: O(1)
//Average Case, Worst Case: O(log N)
//SC:- O(1)
//ADVANTAGES:-
//faster than linear search
//more efficient than other searching algos
//DISADVANTAGES:-
//Array must be sorted
//Binary search requires that the data structure being searched be stored in contiguous memory locations. 
#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> a,int key,int st,int end ){
	
	while(st <= end){
		int mid = st+(end-st)/2;
		if(a[mid] == key)
			return mid;
		else if(a[mid] > key){
			end = mid-1;
		}
		else{
			st = mid+1;
		}	
	}
	return -1;
}

int recursive_bin(vector<int> a,int key,int st,int end ){
	while(st <= end){
		int mid = st+(end-st)/2;
		if(a[mid] == key)
			return mid;
		else if(a[mid] > key){
			return recursive_bin(a,key,st,mid-1);
		}
		else{
			return recursive_bin(a,key,mid+1,end);
		}	
	}
	return -1;
}

int main(){
	
	vector<int> a = {1,4,10,13,16,19,20};
	int n = a.size();
	int key = 10;
	int st=0, end = n-1;
	
	int ans = binary_search(a,key,st,end);
	(ans == -1)?cout<<"key not present" : cout<<"key present";
	cout<<endl;
	int res = recursive_bin(a,key,st,end);
	(res == -1)?cout<<"key not present" : cout<<"key present";
	
	return 0;
}
