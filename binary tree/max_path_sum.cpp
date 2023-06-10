//MAXIMUM PATH SUM IN A BINARY TREE:-
//maximum possible sum of a path in a binary tree, starting and ending at any node
//STRATEGY:-
//for each node,compute:
//1. node val
//2. max path through left child + node val
//3. max path through right child + node val
//4. max path through left child + max path through right child + node val
//in chaaro me se jo max aaega woh hamara max pth sum hoga
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

int maxPathSumUtil(node* root,int &ans){
	if(root == NULL){
		return 0;
	}
	int left = maxPathSumUtil(root->left,ans);
	int right = maxPathSumUtil(root->right,ans);
	
	int nodemax = max(max(root->data,root->data + left + right),max(root->data + left,root->data + right));
	ans = max(ans,nodemax);
	//now we have to return root ke through jaane wala max path hai us max path ki value
	//root->data + left + right hum isiliye nhi lenge kyuki yeh ek complete path ban jaega and isme hamare ancestors i.e. root
	// include nhi ho paenge 
	//    1
	//  2   3
	//4  5 6  7  agar yeh hamara tree hai toh if hum 2 4 5 ke liye root->data + left + right lenge toh hum root means 1 ko include
	// nhi kar paenge that's why we don't take this
	int singlePathSum = max(root->data,max(root->data + left,root->data + right));
	return singlePathSum;
	
}

int maxPathSum(node* root){
	int ans = INT_MIN;
	maxPathSumUtil(root,ans);
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
	
	cout<<maxPathSum(root)<<endl;
	
	return 0;
}
