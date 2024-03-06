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

node* insert(node* root,int key){
	//base case
	if(root == NULL){
		return new node(key);
	}

	if(key < root->data){
		root->left = insert(root->left,key);
	}else{
		root->right = insert(root->right,key);
	}

	return root;
}

int closest(node* root,int target){

	int ans;
	int min_diff = INT_MAX;

	node* temp = root;

	while(temp != NULL){
		int curr_diff = abs(temp->data - target);

		if(curr_diff == 0) return temp->data;

		if(curr_diff < min_diff){
			min_diff = curr_diff;
			ans = temp->data;
		}

		if(target < temp->data){
			temp = temp->left;
		}else{
			temp = temp->right;
		}
	}

	return ans;

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

	int k;
	cin>>k;

	node* root = NULL;

	for(auto y:arr){
		root = insert(root,y);
	}

	cout<<closest(root,k)<<endl;


	return 0;
}