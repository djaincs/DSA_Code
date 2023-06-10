//5 5 5 5 5 5 5 5 5 
//5 4 4 4 4 4 4 4 5
//5 4 3 3 3 3 3 4 5
//5 4 3 2 2 2 3 4 5
//5 4 3 2 1 2 3 4 5
//5 4 3 2 2 2 3 4 5
//5 4 3 3 3 3 3 4 5
//5 4 4 4 4 4 4 4 5
//5 5 5 5 5 5 5 5 5

#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter number of rows:";
	cin>>n;

	int mid = (n+1)/2;
	for(int i=n;i>=1;i--){
		for(int j=n;j>=i;j--)
			cout<<j<<"  ";	
		for(int k=1;k<=2*(i-1)-1;k++)
			cout<<i<<"  ";
		for(int l=i;l<=n;l++){
			if(l==1)
				continue;
			else
				cout<<l<<"  ";	
		}
			
		cout<<endl;	
	}
	
	for(int i=2;i<=n;i++){
		for(int j=n;j>=i;j--)
			cout<<j<<"  ";	
		for(int k=1;k<=2*(i-1)-1;k++)
			cout<<i<<"  ";
		for(int l=i;l<=n;l++){
			cout<<l<<"  ";	
		}
			
		cout<<endl;	
	}
	
	return 0;
}
