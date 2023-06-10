#include<bits/stdc++.h>
using namespace std;

//in both solutions
//SC - O(1)

//TC:- O(N*N)
void bubble_sort(vector<int> &a,int n){
	int temp;
	//no. of paas
	for(int i=0;i<n-1;i++){
		//no. of comparisons
		for(int j=0;j<n-i-1;j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
//The above function always runs O(N^2)
// time even if the array is sorted. It can be optimized by stopping the algorithm if the inner loop didn’t cause any swap. 
//TC- O(n*n)
void opt_bubble_sort(vector<int> &a,int n){
	bool swapped = false;
	for(int i=0;i<n-1;i++){
		//no. of comparisons
		for(int j=0;j<n-i-1;j++){
			if(a[j] > a[j+1]){
				swap(a[j],a[j+1]);
				swapped = true;
			}
		}
		if(swapped == false)
			break;
	}
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
	opt_bubble_sort(a,n);
	cout<<"after sorting elemens of array are:";
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
}
