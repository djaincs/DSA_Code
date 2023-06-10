#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int mySqrt(int x) {
        int l = 0,h=x;
        long long int ans=-1;
        while(l<=h){
            long long int mid = l+(h-l)/2;
            long long int sq = mid*mid;
            if(sq == x)
                return mid;
            if(sq > x)
                h = mid-1;
            else{
                ans = mid;
                l = mid+1;   
            }  
        }
        return ans;
    }
    double morePrecision(int n,int precision,int tempsol){
    	double factor = 1, ans = tempsol;
    	
    	for(int i=0;i<precision;i++){
    		factor = factor/10; //0.1,0.01,0.001.....
    		for(double j=ans; j*j < n ; j = j+factor)
    			ans = j;
		}
    	return ans;
	}
};

int main(){
	
	Solution s;
	
	int n;
	cout<<"enter number:";
	cin>>n;
	int tempsol = s.mySqrt(n);
	
	cout<<s.morePrecision(n,3,tempsol);
	
	return 0;
}
