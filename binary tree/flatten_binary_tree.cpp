//FLATTEN A BINARY TREE:-
//given a binary tree, flatten it into linked list inplace. after flattening left of each node should point to NULL
//& right should contain next node in preorder sequence.(it is not allowed to use other data structures).
//STRATEGY:-
//1. recursively, flatten the left & right subtree
//2. store the left tail & right tail i.e end node or leaf node in left & right subtree
//3. store the right subtree in temp and make left subtree as right subtree
//4. join right subtree with left tail
//5. return right tail bcoz when we flatten the subtree and then waha se jo right tail aaegi toh use apne root ko 
//flatten karne me hum us ele sakte hai & that's why we are returning the right tail
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

void inorder(node* root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);	
}

void flatten(node* &root){
	if(root == NULL || (root->left == NULL && root->right == NULL)) //as tree is already flatten in these cases
		return;
	if(root->left != NULL){
		flatten(root->left);
		
		node* temp = root->right;
		root->right = root->left;
		root->left = NULL;//kyuki ek baar root->left right me chala gya toh left me kuch nhi bachega
		
		//we have to join right subtree with left tail
		node* t = root->right;//root->right, wahi hai jo pahle root->left tha & hum usko root->right me lae the
		while(t->right != NULL){
			t = t->right;
		}
		t->right = temp;
	}
	flatten(root->right);
}

int main(){
	
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	flatten(root);
	inorder(root);
	
	return 0;
}
