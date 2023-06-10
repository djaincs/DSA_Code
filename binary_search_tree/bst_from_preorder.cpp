//CONSTRUCT BST FROM PREORDER TRAVERSAL:-
//NAIVE APPROACH:- TC:- O(n*log n)
//Create a new Node for every value in the array
//Create a BST using these new Nodes and insert them according to the rules of the BST
//Print the inorder of the BST

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

void printpreorder(node* root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";	
	printpreorder(root->left);
	printpreorder(root->right);	
}

static node* temp;

node* createNode(node* root,int data){
	if(root == NULL)
		root = new node(data);
	if(root->data > data)
		root->left = createNode(root->left,data);
	if(root->data < data)
		root->right = createNode(root->right,data);
	return root;			
}

void create(int data){
	temp = createNode(temp,data);
}

//OPTIMAL APPROACH:-
//Initialize the range as {INT_MIN .. INT_MAX}
//The first node will definitely be in range, so create a root node. 
//To construct the left subtree, set the range as {INT_MIN …root->data}. 
//If a value is in the range {INT_MIN .. root->data}, the values are part of the left subtree. 
//To construct the right subtree, set the range as {root->data..max .. INT_MAX}.
node* constructBST(vector<int> pre, int* preIndex, int key, int min, int max){
	//preIndex is used to keep track of index in pre[].
	int n = pre.size();
	
	if(*preIndex >= n)
		return NULL;
	
	node* root1 = NULL;
	if(key>min  && key<max){
		root1 = new node(key);
		//update the index
		*preIndex += 1;
		
		if(*preIndex < n)
			root1->left = constructBST(pre,preIndex, pre[*preIndex], min, key);
		
		//agar preindex ki value abhi bhi n se choti hai toh hum root->right build karenge
		if(*preIndex < n)
			root1->right = constructBST(pre,preIndex,pre[*preIndex], key, max);	
	}
	return root1;
}

int main(){
	vector<int> preorder = {10,5,1,7,40,50};
	
	for(int i=0;i<preorder.size();i++)
		create(preorder[i]);
	inorder(temp);
	cout<<endl;
	
	int preIndex = 0;
	node* ans = constructBST(preorder,&preIndex,preorder[0],INT_MIN,INT_MAX);
	
	printpreorder(ans);
		
	return 0;
}
