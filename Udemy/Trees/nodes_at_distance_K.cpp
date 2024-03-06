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

	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}

void printTree(node* root){
	if(root == NULL ) return;

	printTree(root->left);
	cout<<root->data<<" ";
	printTree(root->right);

	return;
}

void printAtLevelK(node* root, int k){

	//base case
	if(root == NULL) return;
	if(k == 0){
		cout<<root->data<<" ";
		return;
	}

	//recursive case
	printAtLevelK(root->left, k-1);
	printAtLevelK(root->right,k-1);

	return;
}

int printNodesAtDistanceK(node* root, node* target, int k){

	//base case
	if(root == NULL) return -1;

	if(root == target){
		printAtLevelK(root,k);
		return 0;
	}

	//recursive case
	int leftDistance = printNodesAtDistanceK(root->left,target,k);

	if(leftDistance != -1){

		if(leftDistance + 1 == k){
			cout<<root->data<<" ";
		}else{
			printNodesAtDistanceK(root->right,target,k-2-leftDistance);
		}

		return 1 + leftDistance;
	}

	int rightDistance = printNodesAtDistanceK(root->right,target,k);

	if(rightDistance != -1){
		if(rightDistance + 1 == k){ 
			cout<<root->data<<" ";
		}else{
			printNodesAtDistanceK(root->left,target,k-2-rightDistance);
		}

		return 1 + rightDistance;
	}

	return -1;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* root = buildTree();
	// printTree(root);
	node* target = root->left->right;
	int k = 2;

	printNodesAtDistanceK(root,target,k);

	return 0;
}