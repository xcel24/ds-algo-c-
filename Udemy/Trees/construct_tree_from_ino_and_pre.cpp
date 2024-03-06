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

void postorderPrint(node* root){
	//base case
	if(root == NULL) return;

	//recursive case
	postorderPrint(root->left);
	postorderPrint(root->right);
	cout<<root->data<<" ";

	return;
}

int findPos(vector<int>&inorder,int key){
	for(int i=0;i<inorder.size();i++){
		if(inorder[i] == key) return i;
	}

	return -1;
}

node* buildTree(vector<int>&preorder,vector<int>&inorder,int &index,int inorderStart,int inorderEnd){
	//base case
	if(index>=preorder.size() || inorderStart > inorderEnd) return NULL;

	//recursive case
	int element = preorder[index];
	index++;

	node* root = new node(element);

	int pos = findPos(inorder,element);

	root->left = buildTree(preorder,inorder,index,inorderStart,pos-1);
	root->right = buildTree(preorder,inorder,index,pos + 1, inorderEnd);

	return root;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	vector<int>preorder = {1,2,3,4,5};
	vector<int>inorder = {3,2,4,1,5};
	

	int preorderIndex = 0;
	int n = inorder.size();

	node* root = buildTree(preorder,inorder,preorderIndex,0,n-1);

	postorderPrint(root);






	return 0;
}