//        1
//      1 2 1
//    1 2 3 2 1
//  1 2 3 4 3 2 1
//1 2 3 4 5 4 3 2 1

#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter number of rows:";
	cin>>n;
	
	for(int i=1;i<=n;i++){
		for(int k=n-i;k>=1;k--)
			cout<<"  ";
		for(int j=1;j<=i;j++){		
			cout<<j<<" ";
		}
		for(int l=i-1;l>=1;l--)
			cout<<l<<" ";
		cout<<endl;
	}
	
	return 0;
}
