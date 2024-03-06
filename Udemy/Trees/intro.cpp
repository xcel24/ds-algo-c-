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

void preorderPrint(node* root){
	//1 print root
	//2 make recursive call on left
	//3 make recursive call on right

	if(root == NULL) return;

	cout<<root->data<<",";
	preorderPrint(root->left);
	preorderPrint(root->right);
}

void inorderPrint(node* root){
	if(root==NULL) return;

	inorderPrint(root->left);
	cout<<root->data<<",";
	inorderPrint(root->right);
}

void postOrderPrint(node* root){
	if(root == NULL) return;

	postOrderPrint(root->left);
	postOrderPrint(root->right);
	cout<<root->data<<",";
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* root = buildTree();

	preorderPrint(root);
	cout<<endl;

	inorderPrint(root);
	cout<<endl;

	postOrderPrint(root);
	cout<<endl;


	return 0;
}