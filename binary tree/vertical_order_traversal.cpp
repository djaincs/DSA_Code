//VERTICAL TRAVERSAL OF BINARY TREE:-
//Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
//If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.
//-2 -1  0  1  2 ->horizontal distance according to number line
//-  -  -   -  -
//   	1			
// 	 2      3		
//4    5 6    7    ans is :- 4 2 1 5 6 3 7
//horizontal distance ke according levelwise mapping kardo 
// 0 -> 1,5,6
// -1 -> 2
//  1 -> 3
//  -2 -> 4
//   2->7        {-2,-1,0,1,2} =>{4,2,1,5,6,3,7}
#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
		
		node(int val){
			data = val;
			left = NULL;
			right = NULL;
		}
};

vector<int> verticalOrder(node* root){
	//create map of horizontal distance & inside it another map of level & list of nodes
	map<int,map<int,vector<int> > > mp;  
	queue<pair<node*,pair<int,int> > > q; // inside pair of horizontal distance and level
	vector<int> ans;
	
	if(root == NULL)
		return ans;
	q.push(make_pair(root,make_pair(0,0))); //as start from level 0 and root horizontal distance is 0
	
	while(!q.empty()){
		pair<node*,pair<int,int> > temp = q.front();
		q.pop();
		node* curr = temp.first;
		int hd = temp.second.first;
		int level = temp.second.second;
		
		mp[hd][level].push_back(curr->data);
		if(curr->left)
			q.push(make_pair(curr->left,make_pair(hd-1,level+1)));
		if(curr->right)	
			q.push(make_pair(curr->right,make_pair(hd+1,level+1)));
	}
	for(auto i:mp){
		//i belongs to <int,unordered_map<int,vector<int> > > 
		for(auto j:i.second){
			//j belongs to unordered_map<int,vector<int> >
			for(auto k:j.second){
				//k belongs to vector<int>
				ans.push_back(k);
			}
		}
	}
	return ans;	
}

int main(){
	
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	vector<int> ans;
	ans = verticalOrder(root);
	for(auto i:ans){
		cout<<i<<" ";
	}
	
	return 0;
}
