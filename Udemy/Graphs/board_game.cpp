#include<bits/stdc++.h>
using namespace std;

#define M 3
#define N 4

class Node{
public:
	char s;
	unordered_map<char,Node*>children;
	bool isTerminal;
	string word;

	Node(char s){
		this->s = s;
		isTerminal = false;
		word = "";
	}
};

class Trie{

public:
	Node* root;

	Trie(){
		root = new Node('\0');
	}

	void addWord(string word){
		Node* temp = root;

		for(auto ch:word){
			if(temp->children.count(ch) == 0){
				temp->children[ch] = new Node(ch);
			}

			temp = temp->children[ch];
		}
		temp->isTerminal = true;
		temp->word = word;
	}
};

void dfs(char board[M][N],Node* root, int i, int j, bool visited[][N],unordered_set<string>&output){
	//base case
	char ch = board[i][j];
	if(root->children.count(ch) == 0){
		return;
	}

	visited[i][j] = true;
	
	root = root->children[ch];

	if(root->isTerminal){
		output.insert(root->word);
	}

	int dx[] = {1,-1,0,0,1,-1,1,-1};
	int dy[] = {0,0,1,-1,1,1,-1,-1};

	for(int k=0;k<8;k++){
		int ni = i + dx[k];
		int nj = j + dy[k];

		if(ni>=0 and nj>=0 and ni<M and nj<N and !visited[ni][nj]){
			dfs(board,root,ni,nj,visited,output);
		}
	}

	visited[i][j] = false;

	return;
}


int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	//1. Create Trie and store all words in it
	//2. Take container for output
	//3. Make 8-way dfs call
	//4. Print output

	int k;
	cin>>k;
	vector<string>words;

	for(int i=0;i<k;i++){
		string x;
		cin>>x;

		words.push_back(x);
	}

	Trie t;

	for(auto word:words){
		t.addWord(word);
	}


	char board[M][N] = {
		{'S','E','R','T'},
		{'U','N','K','S'},
		{'T','C','A','T'}
	};

	unordered_set<string>output;

	bool visited[M][N];
	memset(visited, false, sizeof(visited[0][0]) * M * N);

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			dfs(board,t.root,i,j,visited,output);
		}
	}

	for(auto word:output){
		cout<<word<<" ";
	}

	return 0;
}