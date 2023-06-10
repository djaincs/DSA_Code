#include<bits/stdc++.h>
using namespace std;

int bin_search(vector<int> a, int size,int key){
	int l = 0,h = size-1;
	while(l<=h){
		int mid = l+(h-l)/2; 
		if(a[mid]==key)
			return mid;
		if(a[mid]<key)
			l = mid+1;
		else
			h = mid-1;		
	}
}

int main(){
	
	vector<int> even = {2,4,6,8,10,12 };
	vector<int> odd = {3,8,11,14,17};
	
	cout<<bin_search(even,even.size(),10)<<endl;
	cout<<bin_search(odd,odd.size(),17)<<endl;
	
	return 0;
}
