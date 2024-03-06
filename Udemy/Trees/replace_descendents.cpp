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

	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

void preOrderPrint(node* root){
	if(root==NULL)return;

	cout<<root->data<<" ";
	preOrderPrint(root->left);
	preOrderPrint(root->right);
}

int replaceDescendents(node* &root){

	//base case
	//it is leaf node
	if(root->left == NULL and root->right == NULL) return root->data;


	//recursive case
	int leftSubTreeSum = 0;
	int rightSubTreeSum = 0;

	if(root->left){
		leftSubTreeSum = replaceDescendents(root->left);
	}
	if(root->right){
		rightSubTreeSum = replaceDescendents(root->right);
	}
	int temp = root->data;
	root->data = leftSubTreeSum + rightSubTreeSum ;

	return root->data + temp;

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* root = buildTree();

	preOrderPrint(root);
	cout<<endl;

	int replacedRoot = replaceDescendents(root);
	cout<<replacedRoot<<endl;

	preOrderPrint(root);



	return 0;
}