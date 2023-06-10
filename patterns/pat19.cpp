//Pascal's triangle
//1
//1 1 
//1 2 1
//1 3 3 1
//1 4 6 4 1

#include<iostream>
using namespace std;

int fact(int n){
		int f=1;
		for(int i=2;i<=n;i++)
			f = f*i;
		return f;
	}

int main(){
	
	int n;
	cout<<"Enter number of rows:";
	cin>>n;
	int a=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			if(j==0 || i==0)
				a=1;
			else{
				a = a * (i-j+1)/j;
			}
			cout<<a<<" ";				
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	//for pyramid pattern with another logic
	
	for(int i=0;i<n;i++){
		for(int k=1;k<=n-i;k++)
			cout<<" ";
		
		for(int j=0;j<=i;j++){
			cout<<fact(i)/(fact(i-j)*fact(j))<<" ";
		}	
		cout<<endl;
	}
	
	return 0;
}
