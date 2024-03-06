#include<bits/stdc++.h>
using namespace std;

#define M 3
#define N 4

class Node{
public:
	char s;
	unordered_map<char,Node*>children;
	string word;
	bool isTerminal;

	Node(char ch){
		s = ch;
		word = "";
		isTerminal = false;
	}
};

class Trie{
public:
	Node* root;

	Trie(){
		root = new Node('\0');
	}

	void addWord(string word){
		Node* temp =root;

		for(auto ch:word){
			if(temp->children.count(ch) == 0){
				temp->children[ch] = new Node(ch);
			}

			temp = temp->children[ch];
		}

		temp->word = word;
		temp->isTerminal = true;
	}
};

void dfs(char board[M][N],Node* root, int i, int j, bool visited[][N],unordered_set<string>&output){
	char ch = board[i][j];

	//base case
	if(root->children.count(ch) == 0) return;

	visited[i][j] = true;
	root = root->children[ch];

	if(root->isTerminal){
		output.insert(root->word);
	}

	//directions
	int dx[] = {1,-1,0,0,1,-1,1,-1};
	int dy[] = {0,0,1,-1,1,1,-1,-1};

	for(int k=0;k<8;k++){
		int nx = i + dx[k];
		int ny = j + dy[k];

		if(nx>=0 and ny>=0 and nx<M and ny<N and !visited[nx][ny]){
			dfs(board,root,nx,ny,visited,output);
		}
	}

	visited[i][j] = false;

	return;

}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	vector<string> words = {"FOR","QUEZ","SNACK","SNACKS","SNAKE","SENS","TUNES","CAT","SUN","ERKCUTN"};

	char board[M][N] = {
		{'S','E','R','T'},
		{'U','N','K','S'},
		{'T','C','A','T'}
	};

	//Step 1 Insert words into Trie

	Trie t;
	for(auto word:words){
		t.addWord(word);
	}

	//Step 2. Take container for final output
	unordered_set<string>output;

	//Step 3. Make dfs Call
	bool visited[M][N];
	memset(visited,false,sizeof(visited[0][0] * M * N));
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			dfs(board,t.root,i,j,visited,output);
		}
	}
	//Step 4. Print the output
	for(auto o:output){
		cout<<o<<" ";
	}

	return 0;
}