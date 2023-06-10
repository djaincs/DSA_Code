//ZIGZAG TRAVERSAL OR SPIRAL TRAVERSAL:-
//   1			->
// 2   3		<-
//4 5 6 7  		->	so, ans is 1 3 2 4 5 6 7
//TC:-O(n)   SC:-O(n)
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

vector<int> zigzagtraversal(node* root){
	vector<int> ans;
	if(root == NULL)
		return ans;
	
	queue<node*> q;
	q.push(root);
	bool leftToRight = true; //for direction of traversal in every level
	while(!q.empty()){
		//use level order traversal
		int size = q.size();
		vector<int> res(size);
		for(int i=0;i<size;i++){
			node* curr = q.front();
			q.pop();
			int index = leftToRight ? i : size-i-1; //if leftToRight=true then index is i i.e. starting index else end index
			res[index] = curr->data;
			
			if(curr->left != NULL)
				q.push(curr->left);
			if(curr->right != NULL)
				q.push(curr->right);		
		}
		//direction change
		leftToRight = !leftToRight;
		for(auto i:res){
			ans.push_back(i);
		}
	}
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
	
	vector<int> ans = zigzagtraversal(root);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}

