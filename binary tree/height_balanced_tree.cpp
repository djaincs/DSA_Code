//HEIGHT BALANCED BINARY TREE:-
//balanced if the absolute difference b/w height of left subtree & right subtree <= 1 i.e. either 0 or 1
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

int height(node* root){
	//TC:-O(n) ,n= no. of nodes in a binary tree
	if(root == NULL)
		return 0;
	
	int leftheight = height(root->left);
	int rightheight = height(root->right);
	int maxheight = max(leftheight,rightheight);
	
	return maxheight+1;	
}

bool isBalanced(node* root){
	//TC:-O(n*n)
	if(root == NULL) //means node ka koi child hai hi nhi toh by default node balanced hai
		return true;
		
	if(isBalanced(root->left) == false) //agar root ke left me koi bhi node unbalanced hui toh return false
		return false;
		
	if(isBalanced(root->right) == false) //agar root ke right me koi bhi node unbalanced hui toh return false
		return false;	
	
	int leftheight = height(root->left);
	int rightheight = height(root->right);	
	
	if(abs(leftheight-rightheight) <= 1)
		return true;
	else
		return false;	
}

bool isBal_opt(node* root,int* height){
	int lh = 0,rh = 0;
	if(root == NULL) 
		return true;
	
	if(isBal_opt(root->left,&lh) == false) 
		return false;
	
	if(isBal_opt(root->right,&rh) == false) 
		return false;	
	
	*height = max(lh,rh)+1;
	
	if(abs(lh-rh)<=1)
		return true;
	else
		return false;			
	
}

void preorder(node* &root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(){

	node* root = new node(1);
	
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	node* a = new node(1);
	a->left = new node(2);
	a->left->left = new node(3);
	
	int ht = 0;
	if(isBal_opt(root,&ht))
		cout<<"Balanced tree"<<endl;
	else
		cout<<"Unbalanced tree"<<endl;
		
	if(isBal_opt(a,&ht))
		cout<<"Balanced tree"<<endl;
	else
		cout<<"Unbalanced tree"<<endl;	
		
//	if(isBalanced(a))
//		cout<<"Balanced tree"<<endl;
//	else
//		cout<<"Unbalanced tree"<<endl;			
	
	return 0;
}
