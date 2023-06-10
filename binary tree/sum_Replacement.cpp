//SUM REPLACEMENT IN A BINARY TREE:-
//replace the value of each node with the sum of all subtree nodes and itself
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

void preorder(node* &root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void sumReplace(node* root){
	//TC:-O(n) //bcoz sumReplace function har node ke liye call ho rha hai and har call me hum o(1) ke operations perform kar rhe hai
	if(root == NULL)
		return;
	
	sumReplace(root->left);
	sumReplace(root->right);
	
	if(root->left != NULL)
		root->data += root->left->data;
	if(root->right != NULL)
		root->data += root->right->data;	
}

int main(){

	node* root = new node(1);
	
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	sumReplace(root);
	preorder(root);
	
	return 0;
}
