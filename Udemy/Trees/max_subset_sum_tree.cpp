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

int maxSubsetSumTree(node* root,bool shouldInclude){
	//base case
	if(root == NULL) return 0;

	//recursive case

	//case 1 when we are including root
	int including = 0;
	int excluding = 0;

	if(shouldInclude){
		including = root->data + maxSubsetSumTree(root->left,false) + maxSubsetSumTree(root->right,false);
	}else{
		excluding = max(maxSubsetSumTree(root->left,true),maxSubsetSumTree(root->left,false)) + max(maxSubsetSumTree(root->right,true) , maxSubsetSumTree(root->right,false));
	}

	return max(including,excluding);
}

pair<int,int> maxSubsetSumTreeAnother(node* root){

	//base case
	if(root == NULL) return {0,0};

	pair<int,int>p;

	//recursive case
	pair<int,int> Left = maxSubsetSumTreeAnother(root->left);
	pair<int,int> Right = maxSubsetSumTreeAnother(root->right);

	p.first = root->data + Left.second + Right.second;
	p.second = max(Left.first,Left.second) + max(Right.first,Right.second);

	return p;

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* root = buildTree();

	cout<<max(maxSubsetSumTree(root,true),maxSubsetSumTree(root,false))<<endl;

	pair<int,int>ans = maxSubsetSumTreeAnother(root);
	cout<<max(ans.first,ans.second)<<endl;


	return 0;
}