//HEIGHT OF BINARY TREE:-
//height is the depth of tree's deepest node
//DIAMETER OF BINARY TREE:-
//diameter is the no. of nodes in alongest path b/w any 2 leaves
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

int diameter(node* root){
	//TC:-O(n*n)
	if(root == NULL)
		return 0;
		
	int leftheight = height(root->left);
	int rightheight = height(root->right);
	
	int currDiam = leftheight + rightheight + 1; //if diameter passing through root
	
	int leftDiam = diameter(root->left);
	int rightDiam = diameter(root->right);
	
	return max(currDiam,max(leftDiam,rightDiam));
	
}

int diameter_optimized(node* root,int* height){
	//instead of calculating height kisi or function me hum apni height ko ek pointer lelenge or use pass karenge same recursive function me
	if(root == NULL){
		*height = 0;
		return 0;	
	}
	 
	int lh = 0,rh = 0;
	int leftDiam = diameter_optimized(root->left,&lh);
	int rightDiam = diameter_optimized(root->right,&rh);
	int currDiam = lh + rh + 1;
	
	*height = max(lh,rh)+1;
	return max(currDiam,max(leftDiam,rightDiam));
}

int main(){

	node* root = new node(1);
	
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	int ht = 0;
	cout<<"Height:"<<height(root)<<endl;
	cout<<"Diameter:"<<diameter(root)<<endl;
	cout<<"Diameter:"<<diameter_optimized(root,&ht)<<endl;
	
	return 0;
}
