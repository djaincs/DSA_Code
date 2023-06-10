//1
//2 3
//4 5 6 7
//8 9 0 1 2 3 4 5
//6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1

#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter number of rows:";
	cin>>n;
	
	int cn = 1;
//	b for no. of elements in row
	for(int i=1,b=1;i<=n;i++,b = b*2){
		for(int j=1;j<=b;j++){
			cout<<cn%10<<" ";
			cn++;
		}
		cout<<endl;
	}
	
	return 0;
}
