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

void levelOrderPrint(node* root){

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* front = q.front();
		q.pop();

		if(front==NULL){
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


node* levelOrderBuild(){

	int d;
	cin>>d;

	node* root = new node(d);

	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* curr = q.front();
		q.pop();

		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			curr->left = new node(c1);
			q.push(curr->left);
		}
		if(c2!=-1){
			curr->right = new node(c2);
			q.push(curr->right);
		}

	}

	return root;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* root = levelOrderBuild();

	levelOrderPrint(root);


	return 0;
}