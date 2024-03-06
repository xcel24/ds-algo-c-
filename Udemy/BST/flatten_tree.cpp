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

class LinkedList{
public:
	node* head;
	node* tail;
};

node* insert(node* root,int x){

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

void printList(node* root){
	while(root != NULL){
		cout<<root->data<<"-->";
		root = root->right;
	}
}

node* flatten(node* root){

	//base case
	if(root == NULL) return NULL;
	if(root->left == NULL or root->right == NULL) return root;

	//recursive case
	node* leftList = flatten(root->left);
	node* rightList = flatten(root->right);

	node* ans = root;

	if(leftList != NULL){
		leftList->left = NULL;

		node* tail = leftList;

		while(tail->right != NULL){
			tail = tail->right;
		}
		tail->right = root;

		ans = leftList;
	}

	if(rightList != NULL){
		rightList->left = NULL;
		root->right = rightList;
	}

	return ans;
}

LinkedList tree2LL(node* root){

	LinkedList l;

	//base case
	if(root == NULL){
		l.head = l.tail = NULL;
		return l;
	}

	//recursive cases
	if(root->left == NULL and root->right == NULL){
		l.head = l.tail = root;
	}

	else if(root->left == NULL and root->right != NULL){
		LinkedList rightSubtree = tree2LL(root->right);

		root->right = rightSubtree.head;

		l.head = root;
		l.tail = rightSubtree.tail;

	}

	else if(root->left != NULL and root->right == NULL){
		LinkedList leftSubtree = tree2LL(root->left);

		leftSubtree.tail->right = root;

		l.head = leftSubtree.head;
		l.tail = root;

	}

	else if(root->left != NULL and root->right != NULL){

		LinkedList leftSubtree = tree2LL(root->left);
		LinkedList rightSubtree = tree2LL(root->right);

		leftSubtree.tail->right = root;
		root->right = rightSubtree.head;

		l.head = leftSubtree.head;
		l.tail = rightSubtree.tail;
	}

	return l;

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

	//node* temp = root;

	//node* list = flatten(root);

	LinkedList ans = tree2LL(root);

	//printList(list);
	//cout<<endl;

	printList(ans.head);


	return 0;
}