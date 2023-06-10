#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node* left,right;
	
		node(int val){
			data = val;
			left = right = NULL;
		}	
};

class BST{
	private:
		node* root;
	public:
		BST(){
			root = NULL;
		}	
		
		pair<node*, node*> search(int key){
			node* curr = root, prev = NULL;
			
			while(curr != NULL){
				if(curr->data == key){	//root node = key then break as we will return in last
					break;
				}
				prev = curr;
				if(curr->data > key){
					curr = curr->left;
				}
				else{
					curr = curr->right;
				}
			}
			return {curr,prev};
		}
		
		void addBST(int key){
			
			pair<node*,node*> p;
			p = find(key);
			
			node* n = new node(key);
			
			if(p.first != NULL){
				cout<<"Duplicate items"<<endl;
			}
			
			if(p.second == NULL){ //means curr is at root
				root = n;
			}
			else{
				if(p.second->data > key){
					p.second->left = n;
				}
				else{
					p.second->right = n;
				}
			}
		}
};

int main(){
	
	BST b;
	b.addBST(10);
	b.addBST(20);
	b.addBST(30);
	b.addBST(40);
	b.addBST(50);
	b.addBST(2);
	b.addBST(1);
	b.addBST(1);
	
	return 0;
}
