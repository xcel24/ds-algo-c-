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

	//base case
	if(root == NULL) return;

	//recursive case
	printTree(root->left);
	cout<<root->data<<" ";
	printTree(root->right);
}

int replaceDescendent(node* root){

	//base case
	if(root==NULL) return 0;

	if(root->left == NULL and root->right == NULL){
		return root->data;
	}

	//recursive case

	int left_sum = replaceDescendent(root->left);
	int right_sum = replaceDescendent(root->right);

	int temp = root->data;

	root->data = left_sum + right_sum;

	return root->data + temp;
}

pair<int,bool> isHeightBalanced(node* root){

	//base case
	if(root == NULL) return {0,true};
	if(root->left == NULL and root->right == NULL) return {1,true};

	//reucrsive case

	pair<int,bool> leftTree = isHeightBalanced(root->left);
	pair<int,bool> rightTree = isHeightBalanced(root->right);

	int diff = abs(leftTree.first - rightTree.first);

	int height = max(leftTree.first,rightTree.first) + 1;

	if(leftTree.second and rightTree.second and diff<=1) return {height, true};
	return {height, false};
}

int maxSubsetSum(node* root, bool shouldInclude){

	//base case
	if(root == NULL) return 0;
	//recursive case

	int included = 0, exluded = 0;

	if(shouldInclude){
		included = root->data + maxSubsetSum(root->left,false) 
					+ maxSubsetSum(root->right,false);
	}else{
		int x = max(maxSubsetSum(root->left,true),maxSubsetSum(root->left,false));
		int y = max(maxSubsetSum(root->right,true),maxSubsetSum(root->right,false));

		exluded = x + y;
	}

	return max(included,exluded);
}

void printAtLevelK(node* root, int k){

	//base case
	if(root==NULL) return;

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
	printTree(root);

	cout<<endl;

	//replaceDescendent(root);

	//printTree(root);

	cout<<endl;

	if(isHeightBalanced(root).second){
		cout<<"Height balanced"<<endl;
	}else{
		cout<<"Not Height balanced"<<endl;
	}

	int x = maxSubsetSum(root,true);
	int y = maxSubsetSum(root,false);

	cout<<max(x,y)<<endl;

	printAtLevelK(root,2);

	return 0;
}