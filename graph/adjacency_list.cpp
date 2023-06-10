#include<bits/stdc++.h>
using namespace std;

template <typename T >
class graph{
	
	public:
		map<T,list<T> > adjl;
		
		void addEdge(T u, T v, bool direction){
			//direction 0 -> undirected graph
			//direction 1 -> directed graph
			adjl[u].push_back(v);
			
			if(direction == 0){
				adjl[v].push_back(u);
			}
		}
		
		void print(){
			for(auto i:adjl){
				cout<<i.first<<"-> ";
				for(auto j:i.second){
					cout<<j<<"  ";
				}
				cout<<endl;
			}
		}
};

int main(){
	
	graph<int> g;
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		//undirected graph
		g.addEdge(u,v,0);
	}
	g.print();
	
//	g.addEdge(0,1,0);
//	g.addEdge(1,2,0);
//	g.addEdge(2,3,0);
//	g.addEdge(3,4,0);
//	g.addEdge(4,0,0);
//	g.addEdge(1,3,0);
	
	
	return 0;
}
