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
	//base case
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

node* lca(node* root, node* p, node* q){
	//base case
	if(root == NULL or root == p or root == q) return root;

	node* leftTree = lca(root->left,p,q);
	node* rightTree = lca(root->right,p,q);

	if(leftTree == NULL) return rightTree;
	if(rightTree == NULL) return leftTree;
	else return root;
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

	for(auto x:arr){
		root = insert(root,x);
	}

	node* ans = lca(root,root->left->left,root->left->right->right);

	cout<<ans->data<<endl;


	return 0;
}