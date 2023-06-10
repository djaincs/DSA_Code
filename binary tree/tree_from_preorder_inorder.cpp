//BUILD TREE FROM PREORDER AND INORDER
//ALGORITHM:-
//1. pick element from preorder and create a node
//2. increment preorder idx.
//3. search for picked element pos in inorder
//4. call to build left subtree from inorder's 0 to pos-1
//5. call to build right subtree from inorder's pos+1 to n
//6. return the node

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

int search(int inorder[],int start,int end,int curr){
	for(int i=start;i<=end;i++){
		if(inorder[i] == curr){
			return i;
		}
	}
	return -1;	
}

void Inorder(node* &root){ //to verify that we get correct tree or not
	if(root == NULL)
		return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);	
}

//When static keyword is used, variable or data members or functions can not be modified again. 
//It is allocated for the lifetime of program. Static functions can be called directly by using class name. 
//Static variables are initialized only once.

node* buildTree(int preorder[],int inorder[],int instart,int inend){
	static int idx = 0; //for traversing in preorder
	
	if(instart > inend){
		return NULL;
	}
	
	int curr = preorder[idx];
	idx++;
	node* root = new node(curr);
	
	if(instart == inend){ //i.e. only 1 element in preoder & inorder
		return root;
	}
	
	int pos = search(inorder,instart,inend,curr);
	
	root->left = buildTree(preorder,inorder,instart,pos-1);
	root->right = buildTree(preorder,inorder,pos+1,inend);
	
	return root;
}

int main(){
	
	int preorder[] = {1,2,4,3,5};
	int inorder[] = {4,2,1,5,3};

	node* root = buildTree(preorder,inorder,0,4);
	Inorder(root);
	
	return 0;
}
