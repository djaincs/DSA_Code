#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adjm(n+1,vector<int>(n+1,0));

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		//for directed graph
		adjm[x][y] =1;
		//for undirected graph
//		adjm[x][y] =1;
//		adjm[y][x] =1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<adjm[i][j]<<" ";
		}
		cout<<endl;
	}
}
