#include <bits/stdc++.h> 
using namespace std;

bool isPossible(vector<int> stalls,int n, int k,int mid){
	int cowsCount = 1;
	int lastpos = stalls[0];
	for(int i=0;i<n;i++){
		if(stalls[i]-lastpos >= mid){
			cowsCount++;
			if(cowsCount == k)
				return true;
			lastpos = stalls[i];	
		}
			
	}
	return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
	sort(stalls.begin(),stalls.end());
	int maxi = INT_MIN,n = stalls.size();
	//int mini=INT_MAX;
	for(int i=0;i<n;i++){
		maxi = max(maxi,stalls[i]);
	}
    int s = 0,e = maxi,ans = -1;
	while(s<=e){
		int mid = s+(e-s)/2;
		if(isPossible(stalls,n,k,mid)){
			ans = mid;
			s = mid+1;
		}
		else
			e = mid-1;
	}
	return ans;
}

int main(){
	
	int n,k;
	cout<<"enter no. of elements in an array:";
	cin>>n;
	cout<<"enter number of cows:";
	cin>>k;
	vector<int> stalls(n);
	for(int i=0;i<n;i++)
		cin>>stalls[i];
	
	cout<<aggressiveCows(stalls,k);
	
	return 0;
}
