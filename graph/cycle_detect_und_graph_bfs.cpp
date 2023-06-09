#include<bits/stdc++.h>
using namespace std;
//TC - linear
bool isCyclicBFS(int node,unordered_map<int,list<int> > &adjl,
        unordered_map<int,bool> &visited){

    unordered_map<int,int> parent; 

    queue<int> q;
    parent[node] = -1;
    visited[node] = true;
    q.push(node);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto i: adjl[curr]){
            if(visited[i] == true && i != parent[curr])
                return true;
            else if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = curr;
            }    
        }
    }
    return false;
}

bool isCyclicDFS(int node,int parent,unordered_map<int,list<int> > &adjl,
        unordered_map<int,bool> &visited){
        	
        	visited[node] = true;
        	
        	for(auto i:adjl[node]){
        		if(!visited[i]){
        			bool cycle = isCyclicDFS(i,node,adjl,visited);
        			if(cycle == true)
        				return true;
				}
				else if(i != parent){
					//cycle present
					return true;
				}
			}
        	return false;
		}

string cycleDetection (vector<pair<int,int>>& edges, int n, int m)
{
    unordered_map<int,list<int> > adjl;
    unordered_map<int,bool> visited;

    for(int i=0;i<m;i++){
		int u = edges[i].first;
		int v = edges[i].second;
		
		adjl[u].push_back(v);
		adjl[v].push_back(u);
	}
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i,-1,adjl,visited);
            if(ans == true)
                return "Yes";
        }
    }
    return "No";
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
	
	cout<<cycleDetection(edges,n,m);
	
	return 0;
}

