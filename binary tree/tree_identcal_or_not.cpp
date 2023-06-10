//IDENTICAL TREE OR NOT:-
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

bool isIdentical(node* root1, node* root2){
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 == NULL)
		return false;
	if(root2 == NULL)
		return false;
	
	if(root1->data == root2->data){
		bool left = isIdentical(root1->left,root2->left);
		bool right = isIdentical(root1->right,root2->right);
		
		if(left && right)
			return true;
	}
	return false;			
}

int main(){
	
	node* root1 = new node(1);
	root1->left = new node(2);
	root1->right = new node(3);
	
//	root1->left->left = new node(4);
//	root1->left->right = new node(5);
//	root1->right->left = new node(6);
//	root1->right->right = new node(7);
	
	node* root2 = new node(1);
	root2->left = new node(2);
	root2->right = new node(3);
	
//	root2->left->left = new node(4);
//	root2->left->right = new node(5);
//	root2->right->left = new node(6);
	//root2->right->right = new node(7);
	
	bool ans = isIdentical(root1,root2);
	if(ans)
		cout<<"Identical tree"<<endl;
	else
		cout<<"Not identical"<<endl;	
	
	return 0;
}
