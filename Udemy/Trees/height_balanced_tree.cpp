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

	if(d == -1) return NULL;

	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

//first value is height and another value is balanced or not
pair<int,bool> isHeightBalanced(node* root){

	//base case
	if(root == NULL){
		return {0,true};
	}

	//recursive case
	pair<int,bool> left = isHeightBalanced(root->left);
	pair<int,bool> right = isHeightBalanced(root->right);
	int diff = abs(left.first - right.first);

	if(left.second and right.second and diff <= 1){
		return {1 + max(left.first,right.first) , true};
	}else{
		return {1 + max(left.first,right.first) , false};
	}
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* root = buildTree();

	pair<int,bool> ans = isHeightBalanced(root);

	if(ans.second){
		cout<<"Balanced"<<endl;
	}else{
		cout<<"Not Balanced"<<endl;
	}

	cout<<"Height of tree is "<<ans.first<<endl;


	return 0;
}