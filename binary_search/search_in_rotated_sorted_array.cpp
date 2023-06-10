#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

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
    int bin_search(vector<int> a,int key,int s,int e){
	int l = s,h = e;
	while(l<=h){
		int mid = l+(h-l)/2; 
		if(a[mid]==key)
			return mid;
		if(a[mid]<key)
			l = mid+1;
		else
			h = mid-1;		
	    }
        return -1;
    }
   
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int pivot = getPivot(nums,n);
       
        if(nums[pivot]<=target && target<=nums[n-1])
            return bin_search(nums,target,pivot,n-1);
        else
            return bin_search(nums,target,0,pivot-1);
    }
};

int main(){
	
	Solution s;
	
	vector<int> a{4,5,6,7,0,1,2};
	int k = 7;
	
	cout<<s.search(a,k);
}
