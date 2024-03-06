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

void preorderPrint(node* root){
	if(root == NULL) return;

	cout<<root->data<<" ";
	preorderPrint(root->left);
	preorderPrint(root->right);
}

void levelOrderPrint(node* root){

	queue<node*> q;

	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* front = q.front();
		q.pop();

		if(front == NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}else{
			if(front->left){
				q.push(front->left);
			}
			if(front->right){
				q.push(front->right);
			}

			cout<<front->data<<" ";
		}
	}
}

int height(node* root){
	//base case
	if(root == NULL) return 0;

	//recursive case
	return 1 + max(height(root->left), height(root->right));
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* root = buildTree();
	preorderPrint(root);
	cout<<endl;

	cout<<height(root)<<endl;

	levelOrderPrint(root);


	return 0;
}