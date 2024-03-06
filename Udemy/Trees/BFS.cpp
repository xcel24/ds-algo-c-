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

void levelOrderPrint(node* root){

	queue<node*> q;

	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* front = q.front();

		if(front == NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}else{
			q.pop();
			if(front->left){
				q.push(front->left);
			}
			if(front->right){
				q.push(front->right);
			}

			cout<<front->data<<" ";
		}
	}

	return;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* root = buildTree();

	levelOrderPrint(root);



	return 0;
}