//LOWEST COMMON ANCESTOR:-

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

bool isPath(node* root,int key,vector<int> &path){
	if(root == NULL)
		return false;
	path.push_back(root->data);
	if(root->data == key)
		return true;
	if(isPath(root->left,key,path) || isPath(root->right,key,path))
		return true;
	
	path.pop_back();
	return false;	
			
}

int LCA(node* root,int n1,int n2){
	//TC:-O(n)
	//but is strategy me hum ek hi node par baar baar ja rhe hai ya toh lca ke liye ya phir getpath ke liye
	vector<int> path1,path2;
	if(!isPath(root,n1,path1) || !isPath(root,n2,path2)) //i.e. no path exist for either n1 or n2 or both from root
		return -1;
	
	int pc; //pc = path change i.e in 1->2->3->4 & 1->2->5 , 2 is the point of path change
	for(pc = 0;pc< path1.size()&& path2.size();pc++){
		if(path1[pc] != path2[pc]) //i.e. we find the path change
			break;
	}
	return path1[pc-1];
}

//optimized:-
node* LCA2(node* root,int n1,int n2){
	if(root == NULL)//means hum leaf node tak pahoch gye hai par hume n1,n2 nhi mile toh hum return karenfe null
		return NULL;
	if(root->data == n1 || root->data == n2)
		return root;
	
	//if not we check in left tree or right tree
	node* leftLCA = LCA2(root->left,n1,n2);	
	node* rightLCA = LCA2(root->right,n1,n2);
	
	if(leftLCA != NULL && rightLCA != NULL)
		return root;//means root->left me ek val hai & root->right me ek val hai that means hum jis node par baithe hai whi hamara lca hai
	
	if(leftLCA != NULL) //means dono values node->left me hai toh hum leftLCA return kardenge
		return leftLCA;
	return rightLCA;			
}

int main(){
	
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	
	int lca = LCA(root,7,6);
	if(lca == -1)
		cout<<"LCA doesn't exist"<<endl;
	else
		cout<<"LCA:"<<lca<<endl;
	
	node* Lca = LCA2(root,4,5);
	if(lca == -1)
		cout<<"LCA doesn't exist"<<endl;
	else
		cout<<"LCA:"<<Lca->data<<endl;	
			
	return 0;
}
