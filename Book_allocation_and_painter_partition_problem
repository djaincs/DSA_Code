//Book allocation problem and painter's partition problem
//same code
#include <bits/stdc++.h> 
using namespace std;

bool isPossible(vector<int> book,int n, int m,int mid){
	int studentCount = 1;
	int pageSum = 0;
	for(int i=0;i<n;i++){
		if(pageSum + book[i] <= mid){
			pageSum += book[i];
		}
		else{
			studentCount++;
			if(studentCount > m || book[i] > mid)
				return false;
			pageSum = book[i];					
		}
	}
	return true;
}

int allocate_book(int n, int m, vector<int> book) 
{	
	int sum=0;
	for(int i=0;i<n;i++){
		sum += book[i];
	}
	
	int s = 0,e = sum,ans = -1;
	while(s<=e){
		int mid = s+(e-s)/2;
		if(isPossible(book,n,m,mid)){
			ans = mid;
			e = mid-1;
		}
		else
			s = mid+1;
	}
	return ans;
}

int main(){
	
	int n,m;
	cout<<"enter no. of elements in an array:";
	cin>>n;
	cout<<"enter number of students:";
	cin>>m;
	vector<int> book(n);
	for(int i=0;i<n;i++)
		cin>>book[i];
	
	cout<<allocate_book(n,m,book);
	
	return 0;
}
