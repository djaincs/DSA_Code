//Print A:-

#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter number of rows:";
	cin>>n;
	int mid = (n+1)/2;
	for(int i=1;i<=n;i++){
		for(int k=n-i;k>=1;k--)
			cout<<"  ";
		for(int j=1;j<=2*i-1;j++){
			if(j==1 || j==2*i-1 || i == mid)
				cout<<"*"<<" ";
			else
				cout<<"  ";	
		}
		
		for(int j=1;j<=i;j++){
			if(i==1 || i==n || (i+j)==n+1)
				cout<<"*"<<" ";
			else
				cout<<"  ";	
		}
		cout<<endl;	
	}
	
	return 0;
}
