//1           1
//2 1       1 2
//3 2 1   1 2 3
//4 3 2 1 2 3 4

#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter number of rows:";
	cin>>n;
	
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--)
			cout<<j<<" ";
		for(int k=1;k<=((n-i)*2)-1;k++)
			cout<<"  ";
		for(int l=1;l<=i;l++){
			if(l==1 && i==n)
				continue;
			else
				cout<<l<<" ";
		}	
			
		cout<<endl;
	}
	
	return 0;
}
