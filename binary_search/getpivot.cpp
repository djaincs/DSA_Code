#include<bits/stdc++.h>
using namespace std;

//get pivot in a rotated sorted array
int getPivot(vector<int> a,int n){
	int s = 0,e = n-1;
	while(s<e){
		int mid = s+(e-s)/2;
		if(a[0] <= a[mid])
			s = mid+1;
		else
			e = mid;	
	}
	return s;
}

int main(){
	
	vector<int> a{8,10,17,1,3};
	int n = a.size();
	
	cout<<getPivot(a,n);
	
	return 0;
}
