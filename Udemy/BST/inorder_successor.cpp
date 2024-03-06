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

node* insert(node* root,int x){
	if(root == NULL){
		return new node(x);
	}

	if(x < root->data){
		root->left = insert(root->left,x);
	}else{
		root->right = insert(root->right,x);
	}

	return root;
}

node* findPath(node* root,int target,int &succ){
	//base case
	if(root == NULL) return NULL;

	if(root->data == target) return root;

	if(root->data > target and root->data < succ){
		succ = root->data;
	}

	//make recursive calls
	if(target < root->data){
		return findPath(root->left,target,succ);
	}else{
		return findPath(root->right,target,succ);
	}
}

int findMin(node* root){
	//base case
	if(root == NULL) return INT_MAX;
	if(root->left == NULL and root->right == NULL) return root->data;

	//recursive case
	int leftMin = findMin(root->left);

	return min(root->data,leftMin);
}

int inorderSuccessor(node* root,int target){

	if(root == NULL) return -1;

	int succ = root->data;

	node* path = findPath(root,target,succ);

	if(path->right == NULL) return succ;
	
	return findMin(path->right);
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	vector<int>arr;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		arr.push_back(x);
	}

	int target;
	cin>>target;

	node* root = NULL;

	for(auto x:arr){
		root = insert(root,x);
	}

	cout<<inorderSuccessor(root,target)<<endl;


	return 0;
}