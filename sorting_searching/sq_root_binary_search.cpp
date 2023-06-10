//Square root using binary search:-
#include<bits/stdc++.h>
using namespace std;

long long int sqrt_int(int x){
	int st = 0,end = x;
	if(st > end)
		return -1;
	
	long long int ans = -1;
	while(st<=end){
		long long int mid = st + (end-st)/2;
		if(mid * mid == x)
		return mid;
		if(mid * mid < x){
			ans = mid;
			st=mid+1;
		}
		else{
			end=mid-1;
		}
	}
	
	return ans;
}

double morePrecision(int n, int precision, int temp_sol){
	//sqrt(37) = 6.08
	//first we add 0.1 then 0.01 then 0.001
	//we get int part from temp_sol which is = to 6 
	//then add 6+0.1 = 6.1*6.1 = 37. ... and update ans when comes <= n
	double factor=1;
	double ans = temp_sol;
	
	for(int i=0;i<precision;i++){
		factor = factor/10;
		for(double j=ans; j*j<n ; j=j+factor){
			ans = j;
		}
	}
	return ans;
}

int main(){
	
	int n;
	cout<<"enter a number:";
	cin>>n;
	int temp_sol = sqrt_int(n);
	
	cout<<morePrecision(n,3,temp_sol);
	return 0;
}
