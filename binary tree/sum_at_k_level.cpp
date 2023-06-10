//FIND THE SUM OF NODES AT Kth LEVEL:-
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

int sumAtK(node* root,int k){
	int level = 0;
	int sum = 0; 
	if(root == NULL)
		return -1;
	
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		node* curr = q.front();
		q.pop();
		
		if(curr != NULL){
			if(level == k){
				sum += curr->data;
			}
			if(curr->left)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);	
		}
		else if(!q.empty()){
			q.push(NULL);
			level++;
		}
	}
	return sum;	
}

int main(){

	node* root = new node(1);
	
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	cout<<sumAtK(root,2);
	
	return 0;
}
