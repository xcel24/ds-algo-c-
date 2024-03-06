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

void printAtLevelK(node* root,int k){

	//base case
	if(root == NULL) return;
	if(k==0 and root != NULL){
		cout<<root->data<<" ";
		return;
	}

	//recursive case
	printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif
	

	node* root = buildTree();


	printAtLevelK(root,2);


	return 0;
}