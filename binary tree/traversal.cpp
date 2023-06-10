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

void inorder(node* &root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);	
}

void postorder(node* &root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";	
}

void levelorder(node* &root){
	if(root == NULL)
		return;
		
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		node* curr = q.front();
		q.pop();
		if(curr != NULL){
			cout<<curr->data<<" ";
			if(curr->left)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);	
		}
		else if(!q.empty()) //curr=NULL hota hai toh hum check karenge q empty toh nhi hui hai na if empty nhi hai toh hum NULL push karenge
			q.push(NULL);
	}
}

int main(){

	node* root = new node(1);
	
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	cout<<"Preorder:";
	preorder(root);
	cout<<endl;
	cout<<"Inorder:";
	inorder(root);
	cout<<endl;
	cout<<"Postorder:";
	postorder(root);
	cout<<endl;
	cout<<"Levelorder:";
	levelorder(root);
	cout<<endl;
	
	return 0;
}
