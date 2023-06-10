//BINARY SEARCH TREE:-
//special type of binary tree used for fast lookup, insertion and deletion.
//in binary tree our TC is O(n) but in BST TC reduced to O(log n)
//RULE:1 -> left subtree of node contains only nodes with keys lesser than node's key
//RULE:2 -> right subtree of node contains only nodes with keys greater than node's key
//RULE:3 -> left & right subtree each must also be a BST. there must be no duplicate nodes.

//inorder of BST is sorted.

#include<iostream>
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

void inorder(node* root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);	
}

node* insertBST(node* root,int val){
	if(root == NULL)
		return new node(val); //root == NULL toh create new node with data as val
	
	if(val < root->data){
		root->left = insertBST(root->left,val);
	}	
	else{
		root->right = insertBST(root->right,val);
	}
	return root;
}

int main(){
	
	node* root = NULL;
	root = insertBST(root,5);
	insertBST(root,1);
	insertBST(root,3);
	insertBST(root,4);
	insertBST(root,2);
	insertBST(root,7);
	
	inorder(root);
	
	return 0;
}
