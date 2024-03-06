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

void traverse(node* root,int d, map<int,vector<int>> &m){

	//base case
	if(root == NULL){
		return;
	}

	m[d].push_back(root->data);

	//recursive case
	traverse(root->left, d - 1, m);
	traverse(root->right, d + 1, m);

}

void verticalOrderPrint(node* root){
	map<int,vector<int>> m;

	int d = 0;

	traverse(root, d, m);

	for(auto x: m){
		vector<int> line = x.second;

		for( auto data:line){
			cout<<data<<" ";
		}
		cout<<endl;
	}

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* root = buildTree();

	verticalOrderPrint(root);


	return 0;
}