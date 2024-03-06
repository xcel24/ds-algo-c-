#include <bits/stdc++.h>
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

node* insert(node* root,int key){

	//base case
	if(root == NULL){
		return new node(key);
	}

	//recursive case
	if(key < root->data){
		root->left = insert(root->left,key);
	}

	if(key >= root->data){
		root->right = insert(root->right,key);
	}

	return root;

}

void inorder(node* root){
	//base case
	if(root == NULL) return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

	return;
}

bool search(node* root, int key){

	//base case
	if(root == NULL) return false;
	if(root->data == key) return true;

	//recursive case
	if(key < root->data){
		return search(root->left,key);
	}else{
		return search(root->right,key);
	}
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

	node* root = NULL;

	for(auto y:arr){
		root = insert(root,y);
	}

	inorder(root);
	cout<<endl;

	if(search(root,14)){
		cout<<"found"<<endl;
	}else{
		cout<<"Not found"<<endl;
	}



	return 0;
}