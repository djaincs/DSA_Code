//A
//A B
//A B C
//A B C D

#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter number of rows:";
	cin>>n;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<char(64+j)<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}

/*
#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter number of rows:";
	cin>>n;
	
	for(int i=1;i<=n;i++){
		for(int j=int('A');j<int('A')+i;j++){
			cout<<char(j)<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
*/


