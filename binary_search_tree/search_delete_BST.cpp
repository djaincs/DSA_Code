//SEARCH AND DELETE IN A BST
//Search - TC : O(n) , worst case TC = height of tree as on each level we do one comparison
//nodes = n, height = h
//1+2+2^2+.....+2^(h-1) = n which iis a gp and sum of gp is:-
//(2^h)-1 = n
//h = log(n+1) so TC O(log n) 

//DELETION:
//Node to be deleted is the leaf: Simply remove it from the tree. 
//Node to be deleted has only one child: Copy the child to the node and delete the node. 
//Node to be deleted has two children: Find the inorder successor of the node. Copy contents of the inorder successor to the node 
//and delete the inorder successor.
//Note: Inorder successor is needed only when the right child is not empty.
// In this particular case, the inorder successor can be obtained by finding the minimum value in the right child of the node.

#include<iostream>
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

node *searchBST(node* root, int key){
	if(root == NULL)
		return NULL;
	if(root->data == key)
		return root;
	
	if(key < root->data)
		return searchBST(root->left,key);
	return searchBST(root->right,key);		
}

node* inorderSuccesor(node* root){
	node* curr = root;
	while(curr && curr->left != NULL)
		curr = curr->left;
	return curr;	
}

node* deleteBST(node* root, int key){
	if(root == NULL)
		return NULL;
	//node* is the pointer of new root after deleting the element
	if(key < root->data){
		root->left = deleteBST(root->left,key); //delete hone ke baad saare changes root->left me reflect honge
	}
	else if(key > root->data){
		root->right = deleteBST(root->right,key);
	}
	else{ //root->data == key
		// node has no child
		if(root->left == NULL && root->right == NULL)
			return NULL;
		// node with only one child or no child	
		else if(root->left == NULL){
			node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}
		//case 3:
		// node with two children: Get the inorder successor
        // (smallest in the right subtree)
		node* temp = inorderSuccesor(root->right); //as right m badi values hoti hai
		// Copy the inorder successor's content to this node
		root->data = temp->data;
		// Delete the inorder successor
		root->right = deleteBST(root->right,temp->data);
	}
	return root;
}

int main(){
	
	node* root = new node(4);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(1);
	root->left->right = new node(3);
	root->right->right  = new node(6);
	
	if(searchBST(root,8)==NULL)
		cout<<"key not found";
	else
		cout<<"key found";	
	cout<<endl;
	
	inorder(root);
	root = deleteBST(root,2);
	cout<<endl;
	inorder(root);	
	
	return 0;
}
