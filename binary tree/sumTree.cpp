//SUM TREE OR NOT:-
//given a binary tree, return true if for every node X in a tree other than leaves,
//its value is equal to sum of its left subtree's value & right subtree's value else return false
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

int sum(node* root){
	if(root == NULL)
		return 0;
	int leftSum = sum(root->left);
	int rightSum = sum(root->right);
	return leftSum+rightSum+root->data;
}

bool isSumTree(node* root){
	//O(n*n)
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return true;
	
	int sumleft = sum(root->left);
	int sumright = sum(root->right);
	if(root->data == sumleft+sumright && isSumTree(root->left) && isSumTree(root->right))
		return true;
	return false;
		
}

//optimized - O(n)
bool isSumTree_opt(node* root){
	// If root is NULL or it's a leaf node, return true
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return true;
	
	// Create an empty queue and add the root node to it
	queue<node*> q;
	q.push(root);
	
	while(!q.empty()){
		 // Remove the front node from the queue
		 node* curr = q.front();
		 q.pop();
		 // If the node is a leaf node, continue
		 if(curr->left==NULL && curr->right == NULL)
		 	continue;
		 // Calculate the sum of the left and right subtrees
		 int sum = 0;
		 if(curr->left != NULL){
		 	sum += curr->left->data;
		 	q.push(curr->left);
		 }
		 if(curr->right != NULL){
		 	sum += curr->right->data;
		 	q.push(curr->right);
		 }
		 // If the sum of the left and right subtrees is not equal to the value of the node, return false
		if(sum != curr->data)
			return false;	
	}
	// If all nodes satisfy the sum tree property, return true
	return true;	
}


int main(){
	
	node* root = new node(3);
	root->left = new node(1);
	root->right = new node(2);
	
	if(isSumTree(root))
		cout<<"Sum tree"<<endl;
	else
		cout<<"not sum tree"<<endl;	
	
	if(isSumTree_opt(root))
		cout<<"Sum tree"<<endl;
	else
		cout<<"not sum tree"<<endl;		
	
	return 0;
}
