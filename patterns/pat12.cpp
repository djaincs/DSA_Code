//1           1
//1 2       2 1
//1 2 3   3 2 1
//1 2 3 4 3 2 1

#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter number of rows:";
	cin>>n;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
			cout<<j<<" ";
		for(int k=1;k<=((n-i)*2)-1;k++)
			cout<<"  ";
		for(int l=i;l>=1;l--){
			if(l==n)
				continue;
			else
				cout<<l<<" ";
		}	
			
		cout<<endl;
	}
	
	return 0;
}
