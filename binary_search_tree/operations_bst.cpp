#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
	
		node(int val){
			data = val;
			left = right = NULL;
		}	
};

class BST{
	private:
		node* root;
		
		void inorderPrint(node* root){
			if(root == NULL){
				return;
			}
			inorderPrint(root->left);
			cout<<root->data<<" ";
			inorderPrint(root->right);
		}
	public:
		BST(){
			root = NULL;
		}	
		
		pair<node*, node*> search(int key){
			node* curr = root, *prev = NULL;
			
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
			p = search(key);
			
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
		
		void inorder(){
			inorderPrint(root);
		}
		
		private:
		void case_a(node* curr, node* prev)
        {
            node *child;
            if(curr->left != nullptr)
                child=curr->left;
            else if(curr->right!=nullptr)
                child=curr->right;
            else
                child=nullptr;
            if(prev==nullptr)
            {
                root=child;
            }
            else
            {
                if(curr->data <prev->data)
                    prev->left=child;
                else
                    prev->right=child;
            }
        }
		
		void case_b(node* curr, node* prev){
			node* succ, *par_succ;
			succ = curr->right;
			par_succ = curr;
			
			while(succ->left != NULL){
				par_succ = succ;
				succ = succ->left;
			}
			case_a(succ,par_succ);
			
			if(prev == NULL){
				root = succ;
			}
			else{
				if(curr->data < prev->data){
					prev->left = succ;
				}
				else{
					prev->right = succ;
				}
			}
			succ->left = curr->left;
			succ->right = curr->right;
			
		}
		public:
		void deleteBST(int key){
			pair<node*, node*> p;
			p = search(key);
			
			
			if(p.first == NULL){
				cout<<"Key not found"<<endl;
				return;
			}
			node *curr, *prev;
			curr = p.first;
			prev = p.second;
				//2 childs present
				if(curr->left != NULL && curr->right != NULL){
					case_b(curr,prev);
				}
				else{ //1 or no child
					case_a(curr,prev);
				}
			
			cout<<curr->data<<" deleted"<<endl;
			delete curr;
		}
};

int main(){
	
	BST b;
	b.addBST(10);
	b.addBST(12);
	b.addBST(8);
	b.addBST(9);
	b.addBST(7);
	b.addBST(11);
	b.addBST(13);
	
	b.inorder();
	cout<<endl;
	b.deleteBST(8);
	b.inorder();
	
	return 0;
}
