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
	if(root == NULL) return;

	cout<<root->data<<" ,";
	preOrderPrint(root->left);
	preOrderPrint(root->right);
}

int height(node* root){
	if(root==NULL) return 0;

	int h1 = height(root->left);
	int h2 = height(root->right);

	return 1 + max(h1,h2);
}

int diameterOfTree(node* root){

	//base case
	if(root==NULL) return 0;

	//recursive case
	int d1 = height(root->left) + height(root->right);
	int d2 = diameterOfTree(root->left);
	int d3 = diameterOfTree(root->right);

	return max(d1,max(d2,d3));
}


pair<int,int> optimisedDiameter(node* root){

	pair<int,int>p;

	//base case
	if(root == NULL){
		p.first = p.second = 0;

		return p;
	}


	//recursive case

	pair<int,int>Left = optimisedDiameter(root->left);
	pair<int,int>Right = optimisedDiameter(root->right);

	p.first = max(Left.first,Right.first) + 1;

	int D1 = Left.first + Right.first;
	int D2 = Left.second;
	int D3 = Right.second;

	p.second = max(D1,max(D2,D3));

	return p;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* root = buildTree();

	preOrderPrint(root);
	cout<<endl;

	cout<<diameterOfTree(root)<<endl;
	cout<<optimisedDiameter(root).second<<endl;


	return 0;
}