//	      5
//      5 4
//    5 4 3
//  5 4 3 2
//5 4 3 2 1

#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter number of rows:";
	cin>>n;
	
	for(int i=n;i>=1;i--){
		for(int k=i-1;k>=1;k--)
			cout<<char(32);
		for(int j=n;j>=i;j--){
			cout<<j;
		}
		cout<<endl;
	}
	
	return 0;
}
