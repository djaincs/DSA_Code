//BUILD TREE FROM POSTORDER AND INORDER:-
//ALGORITHM:-
//1. start from end of postorder & pich an element to create node
//2. decrement postorder idx
//3. search for picked element pos in inorder
//4. call to build right subtree from inorder's pos+1 to n //1st we are building right subtree bcoz postorder is exactly opposite to preorder
//5. call to build left subtree from inorder's 0 to pos-1
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

node* buildTree(int postorder[],int inorder[], int instart,int inend,int n){
	static int idx = n-1;
	
	if(instart > inend)
		return NULL;
	
	int curr = postorder[idx];
	idx--;
	node* root = new node(curr);
	
	if(instart == inend)
		return root;
	
	int pos = search(inorder,instart,inend,curr);
	root->right = buildTree(postorder,inorder,pos+1,inend,n);
	root->left = buildTree(postorder,inorder,instart,pos-1,n);
	
	return root;
}

int search2(vector<int>& inorder,int start,int end,int curr){
        for(int i=start;i<=end;i++){
            if(inorder[i] == curr)
                return i;
        }
        return -1;
    }
int index;
node* tree(vector<int>& inorder, vector<int>& postorder,int start,int end)
    {
    	
        if(start > end)
            return NULL;
        int curr = postorder[index];
        index++;
        node* root = new node(curr);
        if(start == end)
            return root;

        int pos = search2(inorder,start,end,curr);
        root->right = tree(inorder,postorder,pos+1,end);
        root->left = tree(inorder,postorder,start,pos-1);

        return root;
    }

node* buildtre(vector<int>& inorder, vector<int>& postorder) {
        int isize = inorder.size();
        reverse(postorder.begin(),postorder.end());
        index=0;
        return tree(inorder,postorder,0,isize-1);
}

int main(){
	
	int postorder[] = {4,2,5,3,1};
	int inorder[] = {4,2,1,5,3};
	int n = sizeof(postorder)/sizeof(0);

	node* root = buildTree(postorder,inorder,0,n-1,n);
	Inorder(root);
	cout<<endl;
	
	vector<int> post{4,2,5,3,1};
	vector<int> in{4,2,1,5,3};
	
	node* ans = buildtre(in,post);
	Inorder(ans);
	
	return 0;
}
