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

vector<int> rightView(node* root){

	//build a queue
	queue<node*>q;

	q.push(root);
	q.push(NULL);

	vector<int>ans;

	while(!q.empty()){

		node* curr = q.front();

		q.pop();

		if(curr == NULL){
			if(!q.empty()){
				q.push(NULL);
			}
		}else{
			if(curr->left){
				q.push(curr->left);
			}
			if(curr->right){
				q.push(curr->right);
			}
		}

		if(! q.empty() and q.front() == NULL){
			ans.push_back(curr->data);
		}
	}

	return ans;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* root = buildTree();
	printTree(root);

	cout<<endl;

	vector<int>ans = rightView(root);

	for(auto x:ans){
		cout<<x<<" ";
	}

	return 0;
}