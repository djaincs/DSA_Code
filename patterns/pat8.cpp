//      1
//    1 2
//  1 2 3
//1 2 3 4

#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter number of rows:";
	cin>>n;
	
	for(int i=1;i<=n;i++){
		for(int k=n-i;k>=1;k--)
			cout<<char(32);
		for(int j=1;j<=i;j++){		
			cout<<j;
		}
		cout<<endl;
	}
	
	return 0;
}
