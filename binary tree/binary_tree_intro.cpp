//BINARY TREE:-
//data is stored in hierarchical manner
//in binary tree at every node there are atmost 2 children, left child and right child
//PROPERTIES OF BINARY TREE:-
//1. Maximum nodes at level (L = 2^L) i.e. at L=0,2^0=1 nodes ,,at L=1,2^1=2 nodes and so on
//2. Maximum nodes in atree at height (H = 2^H-1)
//3. for N nodes min. possible height or min. no. of levels are log2(N+1) //derived from 2.
//4. a binary tree with L leaves has atleast log2(n+1)+1 no. of levels 

//TRAVERSAL:-
//preorder - Root,left,right
//inorder -  left,root,right
//postorder -left,right,root

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



int main(){
	
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->right->right = new node(5);
	
	
	return 0;
}
