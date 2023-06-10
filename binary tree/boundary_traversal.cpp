//BOUNDARY TRAVERSAL:-
//print:-
//1. left boundary nodes
//2. leaf nodes
//3. reverse right boundary nodes
//     	 1			
// 	 2      3		
//4    5   6   7     so,ans is 1 2 4 8 9 6 7 3  not 3 7 its 7 3
//	8    9
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

void traverseleft(node* root,vector<int> &ans){
	//if null or leaf node return;
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return;
	
	ans.push_back(root->data);
	if(root->left != NULL)
		traverseleft(root->left,ans);
	else
		traverseleft(root->right,ans);	
		
			
}

void traverseleaf(node* root,vector<int> &ans){
	if(root == NULL)
		return;
	if(root->left == NULL && root->right == NULL)	{
		ans.push_back(root->data);
		return;
	}
	traverseleaf(root->left,ans);
	traverseleaf(root->right,ans);
}

void traverseright(node* root,vector<int> &ans){
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return;
	
	if(root->right)
		traverseright(root->right,ans);
	else
		traverseright(root->left,ans);
	//pahle leaf tak pahochenge then reverse me aakar print karenge
	ans.push_back(root->data);			
}

vector<int> boundary(node* root){
	vector<int> ans;
	if(root == NULL)
		return ans;
	ans.push_back(root->data);
	//print left boundary
	traverseleft(root->left,ans);
	//print leaf nodes
	
	//left subtree leaf nodes
	traverseleaf(root->left,ans);
	//right subtree leaf nodes	
	traverseleaf(root->right,ans);
	
	//print right boundary 
	traverseright(root->right,ans);
	return ans;
}

int main(){
	
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	vector<int> ans = boundary(root);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
