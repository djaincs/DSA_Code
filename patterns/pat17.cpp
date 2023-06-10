//Print Swastik:-

#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter number of rows:";
	cin>>n;

	int mid = (n+1)/2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==mid || j==mid || (i==1 && j>mid) || (i==n && j<mid) || (j==1 && i<mid) || (j==n && i>mid))
				cout<<"*"<<" ";
			else
				cout<<"  ";	
		}
		cout<<endl;	
	}
	
	return 0;
}
