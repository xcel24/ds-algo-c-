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

vector<int> findCousins(node* root,int node_to_find){

	queue<node*>q;

	q.push(root);

	bool marker = true;

	while(!q.empty() && marker){
		int n = q.size();

		for(int i=0;i<n;i++){
			node* curr = q.front();
			q.pop();

			if((curr->left && curr->left->data == node_to_find) || (curr->right && curr->right->data == node_to_find)){
				marker = false;
			}else{
				if(curr->left) q.push(curr->left);
				if(curr->right) q.push(curr->right);
			}
		}
	}

	vector<int>ans;
	
	if(q.empty()) return ans;

	while(!q.empty()){
		node* curr = q.front();
		q.pop();

		ans.push_back(curr->data);
	}

	return ans;
}


int main(){


	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* root = buildTree();

	vector<int>ans = findCousins(root,5);

	for(auto x:ans){
		cout<<x<<" ";
	}

	return 0;
}