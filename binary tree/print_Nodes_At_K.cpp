	//PRINT ALL NODES AT DISTANCE K:-
//Case 1:-find in node's subtree , Case 2:- find in node's ancestors
//for case 2:- find the distance d of all ancestors from target node & for all ancestors search other subtree nodes at(K-d) 
//if target node is in left subtree search in right subtree & vice versa
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

//case 1:-
void printSubtreeNodes(node* root, int k){
	if(root == NULL || k < 0)
		return;
	
	if(k == 0){
		cout<<root->data<<" ";
	}
	printSubtreeNodes(root->left,k-1);
	printSubtreeNodes(root->right,k-1);				
}

//case 2:-
int printNodesAtK(node* root,node* target,int k){
//return type int liya hai kyuki hume target node se ancestor ki distance chahiye,d,& by the help of this we convert this case into case 1
	if(root == NULL)
		return -1;
	
	if(root == target){
		printSubtreeNodes(root,k);
		return 0; //since root == target i.e we don't need to move further to find target so return 0
	}	
	int dl = printNodesAtK(root->left,target,k);//dl =distance left //k-1 isiliye nhi kiya kyuki hume original distance chahiye target tak ki
	if(dl != -1){
		if(dl+1 == k){ //means hum jis current node par hai woh hamare target se kth distance par hai
			cout<<root->data<<" ";
		}
		else{
			printSubtreeNodes(root->right,k-dl-2);
		}
		return 1+dl;
	}
	int dr = printNodesAtK(root->right,target,k);//dr = distance right
	if(dr != -1){
		if(dr+1 == k){
			cout<<root->data<<" ";
		}
		else{
			printSubtreeNodes(root->left,k-dr-2);
		}
		return 1+dr;
	}
	return -1;
}

int main(){
	
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	printNodesAtK(root,root->left->left,4);
	return 0;
}
