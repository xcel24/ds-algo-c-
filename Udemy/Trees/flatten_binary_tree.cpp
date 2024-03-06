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

	if(root == NULL) return;

	printTree(root->left);
	cout<<root->data<<" ";
	printTree(root->right);
}

node* flatten(node* root){

	//base case
	if(root == NULL or (root->left == NULL and root->right == NULL)) return root;

	//recursive case

	node* leftTree = flatten(root->left);
	node* rightTree = flatten(root->right);

	node* tail = leftTree;

	root->left = NULL;

	if(leftTree != NULL){
		while(tail->right != NULL){
			tail = tail->right;
		}

		root->left = NULL;
		root->right = leftTree;
		tail->right = rightTree;
	}else{
		root->right = rightTree;
	}

	return root;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* root = buildTree();

	//printTree(root);

	node* flattenRoot = flatten(root);

	printTree(flattenRoot);

	return 0;
}