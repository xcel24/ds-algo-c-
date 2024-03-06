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

node* insert(node* root,vector<int>&arr,int s,int e){

	//find the mid element
	if(s > e) return NULL;

	int mid = (s+e)/2;

	root = new node(arr[mid]);

	root->left = insert(root->left,arr,s,mid-1);

	root->right = insert(root->right,arr,mid+1,e);


	return root;


}

void inorder(node* root){
	//base case
	if(root == NULL) return;

	//recursive case
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

	return;
}

int height(node* root){
	//base case
	if(root == NULL) return 0;

	//recursive case
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return max(leftHeight,rightHeight) + 1;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	vector<int>arr = {1,2,3,4,5,6,7};
	int n = arr.size();

	node* root = NULL;

	root = insert(root,arr,0,n-1);

	//inorder(root);
	//cout<<endl;

	cout<<"height is "<<height(root)<<endl;

	return 0;
}