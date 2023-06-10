//COUNT ALL THE NODES IN A BINARY TREE:-
//SUM OF ALL NODES IN A BINARY TREE:-
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

int countNodes(node* root){
	if(root == NULL)
		return 0;
	
	return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumNodes(node* root){
	if(root == NULL)
		return 0;
		
	return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

int main(){

	node* root = new node(1);
	
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	cout<<"Count:-"<<countNodes(root)<<endl;
	cout<<"Sum:-"<<sumNodes(root);
	
	return 0;
}
