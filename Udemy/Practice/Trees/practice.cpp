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


void preorderTraversal(node* root){
	//base case
	if(root == NULL)return;

	//recursive case
	cout<<root->data<<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);

	return;
}

void inorderTraversal(node* root){
	//base case
	if(root == NULL)return;

	//recursive case
	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);

	return;
}

void postorderTraversal(node* root){
	//base case
	if(root == NULL) return;

	//recursive case
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout<<root->data<<" ";

	return; 
}

void bfs(node* root){
	queue<node*>q;

	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* curr = q.front();
		q.pop();

		if(curr == NULL){
			if(!q.empty()){
				q.push(NULL);
			}
			cout<<endl;
		}else{
			cout<<curr->data<<" ";

			if(curr->left) q.push(curr->left);
			if(curr->right) q.push(curr->right);
		}
	}

	return;
}

void verticalorderTraversal(node* root,int level, map<int,vector<int>>&m){

	//base case
	if(root == NULL)return;

	//recursive case
	m[level].push_back(root->data);

	verticalorderTraversal(root->left,level-1,m);
	verticalorderTraversal(root->right,level+1,m);

	return;

}

void diagonalTraversal(node* root,int level,map<int,vector<int>>&m){
	//base case
	if(root == NULL) return;

	//recursive case
	m[level].push_back(root->data);

	diagonalTraversal(root->left,level + 1,m);
	diagonalTraversal(root->right,level,m);

	return;
}

vector<int>leftView(node* root){
	vector<int>ans;
	vector<int>temp;

	queue<node*>q;

	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* curr = q.front();
		q.pop();

		if(curr == NULL){
			if(!q.empty()){
				q.push(NULL);
			}

			if(temp.size()>0){
				ans.push_back(temp[0]);
			}

			temp.clear();
		}else{
			temp.push_back(curr->data);

			if(curr->left) q.push(curr->left);
			if(curr->right) q.push(curr->right);
		}
	}

	return ans;
}

vector<int>rightView(node* root){
	vector<int>ans;
	vector<int>temp;

	queue<node*>q;

	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* curr = q.front();
		q.pop();

		if(curr == NULL){
			if(!q.empty()){
				q.push(NULL);
			}

			if(temp.size()>0){
				ans.push_back(temp[temp.size()-1]);
			}

			temp.clear();
		}else{
			temp.push_back(curr->data);

			if(curr->left) q.push(curr->left);
			if(curr->right) q.push(curr->right);
		}
	}

	return ans;
}

node* lca(node* root, int a, int b){
	//base case
	if(root == NULL or root->data == a or root->data == b) return root;

	//recursive case
	node* leftSubtree = lca(root->left,a,b);
	node* rightSubtree = lca(root->right,a,b);

	if(leftSubtree == NULL) return rightSubtree;
	if(rightSubtree == NULL) return leftSubtree;
	else return root;
}

void pathToNode(node* root,int target,vector<int>temp,vector<int>&path){
	//base case
	if(root == NULL) return;
	if(root->data == target){
		temp.push_back(root->data);
		path = temp;

	}

	//recursive calls
	temp.push_back(root->data);
	pathToNode(root->left,target,temp,path);
	pathToNode(root->right,target,temp,path);
	temp.pop_back();

	return;
}

void findCousins(node* root, int target){
	queue<node*>q;

	q.push(root);

	bool marker = true;

	while(!q.empty() & marker){

		int n = q.size();

		for(int i=0;i<n;i++){
			node* curr = q.front();
			q.pop();

			if((curr->left and curr->left->data == target) or (curr->right and curr->right->data == target)){
				marker = false;
			}else{
				if(curr->left) q.push(curr->left);
				if(curr->right) q.push(curr->right);
			}
		}
	}

	while(!q.empty()){
		node* curr = q.front();
		q.pop();

		cout<<curr->data<<" ";
	}

	cout<<endl;
}

int height(node* root){
	if(root == NULL) return 0;

	int h1 = height(root->left);
	int h2 = height(root->right);

	return max(h1,h2) + 1;
}

int diameter(node* root){
	//base case
	if(root == NULL) return 0;

	//recursive case
	int d1 = height(root->left) + height(root->right);
	int d2 = diameter(root->left);
	int d3 = diameter(root->right);

	return max(d1,max(d2,d3));
}

pair<node*,node*>flatten(node* root){
	//base case
	pair<node*,node*>ans;

	if(root == NULL) return {NULL,NULL};
	if(root->left == NULL and root->right == NULL){
		return {root,root};
	}

	if(root->left != NULL and root->right == NULL){
		pair<node*,node*>leftSubtree = flatten(root->left);

		leftSubtree.second->right = root;
		ans.first = leftSubtree.first;
		ans.second = root;
	}

	if(root->left == NULL and root->right != NULL){
		pair<node*,node*>rightSubtree = flatten(root->right);

		root->right = rightSubtree.first;

		ans.first = root;
		ans.second = rightSubtree.second;
	}
	else if(root->left != NULL and root->right != NULL){
		pair<node*,node*>leftSubtree = flatten(root->left);
		pair<node*,node*>rightSubtree = flatten(root->right);

		leftSubtree.second->right = root;
		root->right = rightSubtree.first;

		ans.first = leftSubtree.first;
		ans.second = rightSubtree.second;
	}

	return ans;

}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	node* root = buildTree();

	cout<<"preorderTraversal"<<endl;
	preorderTraversal(root);
	cout<<endl;
	
	cout<<"inorderTraversal"<<endl;
	inorderTraversal(root);
	cout<<endl;

	cout<<"postorderTraversal"<<endl;
	postorderTraversal(root);
	cout<<endl;

	cout<<"bfs"<<endl;
	bfs(root);
	cout<<endl;

	cout<<"vertical order traversal"<<endl;
	map<int,vector<int>>m;
	verticalorderTraversal(root,0,m);
	for(auto it:m){
		cout<<it.first<<"-->";
		for(auto j:it.second) cout<<j<<" ";
		cout<<endl;
	}
	cout<<endl;

	m.clear();

	cout<<"diagonal traversal"<<endl;
	diagonalTraversal(root,0,m);
	for(auto it:m){
		cout<<it.first<<"-->";
		for(auto j:it.second) cout<<j<<" ";
		cout<<endl;
	}
	cout<<endl;

	cout<<"left view"<<endl;
	vector<int>lview = leftView(root);
	for(auto x:lview)cout<<x<<" ";
	cout<<endl;

	cout<<"right view"<<endl;
	vector<int>rview = rightView(root);
	for(auto x:rview)cout<<x<<" ";
	cout<<endl;

	node* lcaVal = lca(root,4,7);
	cout<<"lca is "<<lcaVal->data<<endl;

	vector<int>path;
	vector<int> temp;


	pathToNode(root,54,temp,path);
	if(path.size() == 0) cout<<"no path";
	else{
		for(auto x:path){
		cout<<x<<" ";
		}
	}
	cout<<endl;

	cout<<"cousins are "<<endl;
	findCousins(root,13);

	cout<<"diameter is"<<endl;
	cout<<diameter(root)<<endl;

	cout<<"Flatten tree to LL"<<endl;
	pair<node*,node*> ll = flatten(root);

	while(ll.first != NULL){
		cout<<ll.first->data<<",";
		ll.first = ll.first->right;
	}

	cout<<endl;


	return 0;
}