//1
//2 6
//3 7 10
//4 8 11 13
//5 9 12 14 15

#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter number of rows:";
	cin>>n;
	
	for(int i=1;i<=n;i++){
		int num = i;
		for(int j=1;j<=i;j++){
			cout<<num<<" ";
			num = num + n-j;
		}
		cout<<endl;
	}
	
	return 0;
}
