#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

node* buildTree(){
	int d;
	cin>>d;

	if(d==-1) return NULL;

	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}

void printTree(node* root){
	//base case
	if(root == NULL) return;

	printTree(root->left);
	cout<<root->data<<" ";
	printTree(root->right);
}

vector<int>leftView(node* root){

	queue<node*> q;
	vector<int>ans;

	q.push(root);
	q.push(NULL);

	ans.push_back(root->data);

	while(!q.empty()){
		node* curr = q.front();
		q.pop();

		if(curr == NULL){

			if(!q.empty()){
				q.push(NULL);
			}

		}else{
			if(curr->left){
				q.push(curr->left);
			}
			if(curr->right){
				q.push(curr->right);
			}
		}

		if(curr == NULL and !q.empty() and q.front() != NULL){
			ans.push_back(q.front()->data);
		}
	}

	return ans;


}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* root = buildTree();
	// printTree(root);

	vector<int>ans = leftView(root);
	for(auto x:ans){
		cout<<x<<" ";
	}

	return 0;
}