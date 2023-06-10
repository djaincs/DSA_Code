//SHORTEST DISTANCE B/W 2 NODES:-
//distance b/w 2 nodes is the min no. of edges to be traversed to reach from one node to another
//STRATEGY:-
//1. find the lowest common ancestor(LCA)
//2. find distance of n1(d1) & n2(d2) from LCA
//3. return d1+d2

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

node* lca(node* root,int n1,int n2){
	if(root == NULL)
		return NULL;
	
	if(root->data == n1 || root->data == n2)
		return root;
	
	node* leftLCA = lca(root->left,n1,n2);
	node* rightLCA = lca(root->right,n1,n2);
	
	if(leftLCA != NULL && rightLCA != NULL)
		return root;
	
	if(leftLCA != NULL)
		return leftLCA;
	return rightLCA;				
}

int findDist(node* root,int k,int dist){
	if(root == NULL)
		return -1;
	
	if(root->data == k)
		return dist;
	
	int left = findDist(root->left,k,dist+1);
	//root ke left me find karenge apni key k ko & kyuki hum ek level travel karke next level par jaenge toh distance+1 ho jaega
	int right = findDist(root->right,k,dist+1);
	
	if(left != -1) //left me hume apni value mil jaati hai toh left distance return kardenge else return right distance
		return left;
	return right;			
}

int distanceBtwNodes(node* root,int n1,int n2){
	node* LCA = lca(root,n1,n2);
	
	int d1 = findDist(LCA,n1,0); //distance b/w lca & n1 and initial distance is 0 i.e count is 0
	int d2 = findDist(LCA,n2,0);
	
	return d1+d2;
}

int main(){
	
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	int n1 = 4,n2 = 1;
	cout<<"Distance between "<<n1<<" & "<<n2<<" is:"<<distanceBtwNodes(root,n1,n2);
	
	return 0;
}
