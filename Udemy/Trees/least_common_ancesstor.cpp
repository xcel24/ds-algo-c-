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

 void helper(node* A, int B, vector<int>temp,vector<int>&ans){
     
     //base case
     if(A == NULL) return;
     
     if(A->data == B){
         temp.push_back(A->data);
         ans = temp;
         
         return;
     }
     
     //recursive case
     temp.push_back(A->data);
     helper(A->left,B,temp,ans);
     helper(A->right,B,temp,ans);
     temp.pop_back();
     
     return;
     
 }

int lca(node* root,int a,int b){
	vector<int>aPath;
	vector<int>bPath;
    vector<int>temp;

    helper(root,a,temp,aPath);

    temp.clear();

    helper(root,b,temp,bPath);

	if(aPath.size() == 0 or bPath.size() == 0) return -1;

	int i=0, j=0;

	int ans = aPath[0];

	while(i<aPath.size() and j<bPath.size()){
		if(aPath[i] == bPath[j]){

			ans = aPath[i];

			i++;
			j++;
		}else{
			break;
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

	int a = 5;
	int b = 7;

	int ans = lca(root,a,b);

	cout<<ans<<endl;


	return 0;
}