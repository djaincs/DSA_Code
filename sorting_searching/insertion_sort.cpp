//INSERTION SORT

//The worst case time complexity of Insertion sort is O(N^2)
//The average case time complexity of Insertion sort is O(N^2)
//The time complexity of the best case is O(N).

//space complexity of Insertion Sort’s is O(1)
//space complexity of Insertion Sort’s Recursive Approach is O(n) due to the recursion stack.

//What are the Algorithmic Paradigm of Insertion Sort algorithm?
//Insertion Sort algorithm follows incremental approach

//inplace, stable
 
#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &a, int n){
	for(int i=1;i<n;i++){
		//starting from 1 by assuming that 1st number is at correct position
		int curr = a[i];
		int j = i-1;
		while(a[j] > curr and j>=0){
			a[j+1] = a[j];
			j--; //j>=0 isiliye lagaya hai ki kahi j-- karte karte 0 se choti na ho jae value
		}
		a[j+1] = curr;
	}
}

//Starting from the second element, traverse through the input array from left to right.
//For each element, compare it with the elements in the sorted subarray to its left, starting from the rightmost element.
//If an element in the sorted subarray is greater than the current element, shift that element one position to the right.
//Repeat step 3 until you find an element that is less than or equal to the current element.
//Insert the current element into the position immediately to the right of the element found in step 4.
//Repeat steps 2-5 for all remaining elements in the unsorted subarray.

void recursive_insertion_sort(vector<int> &a, int n){
	if(n<=1)
		return;
	
	recursive_insertion_sort(a,n-1);
	
	int last = a[n-1];
	int j = n-2;
	
	while(j>=0 and a[j]>last){
		a[j+1] = a[j];
		j--;
	}
	a[j+1] = last;
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
	recursive_insertion_sort(a,n);
	cout<<"after sorting elemens of array are:";
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
}
