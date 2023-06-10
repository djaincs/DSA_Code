#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<int> > adjl;
unordered_map<int,bool> visited;

void make_adjl(vector<pair<int,int>> edges){
	for(int i=0;i<edges.size();i++){
		int u = edges[i].first;
		int v = edges[i].second;
		
		adjl[u].push_back(v);
		adjl[v].push_back(u);
	}
	
}

void bfs(int node){
	queue<int> q;
	q.push(node);
	visited[node] = 1;
	
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		cout<<curr<<" ";
		
		//traversing neighbors of curr
		for(auto i:adjl[curr]){
			if(!visited[i]){
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<pair<int,int>> edges;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		edges.push_back({u,v});
	}
	
	make_adjl(edges);
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
			bfs(i);
		}
	}
	
	return 0;
}
