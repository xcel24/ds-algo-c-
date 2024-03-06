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

void printPreorder(node* root){
	//base case
	if(root == NULL) return;

	//recursive case
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);

	return;
}

node* buildTree(vector<int>&postorder,int postStart,int postEnd,vector<int>&inorder,int inoStart,int inoEnd,map<int,int>&store){

	//base case
	if(postStart > postEnd || inoStart > inoEnd) return NULL;

	//recursive case
	int element = postorder[postEnd];
	node* root = new node(element);

	int pos = store[element];
	int numsLeft = pos - inoStart;

	//make recursive calls
	root->left = buildTree(postorder,postStart,postStart + numsLeft-1,inorder,inoStart,pos-1,store);
	root->right = buildTree(postorder,postStart + numsLeft,postEnd-1,inorder,pos+1,inoEnd,store);

	return root;


}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	vector<int>inorder = {4,2,5,1,6,3,7};
	vector<int>postorder = {4,5,2,6,7,3,1};

	int n = postorder.size();

	map<int,int>store;

	for(int i=0;i<n;i++){
		store[inorder[i]] = i;
	}

	node* root = buildTree(postorder,0,n-1,inorder,0,n-1,store);

	printPreorder(root);




	return 0;
}