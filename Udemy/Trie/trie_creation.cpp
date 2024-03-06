#include<bits/stdc++.h>
using namespace std;

class node{
public:
	char data;
	unordered_map<char,node*>m;
	bool isTerminal;

	node(char data){
		this->data = data;
		isTerminal = false;
	}
};

class Trie{

	node* root;

public:
	Trie(){
		root = new node('\0');
	}

	void insert(string word){
		node* temp = root;

		for(auto ch:word){
			if(temp->m.count(ch) == 0){
				node* n = new node(ch);
				temp->m[ch] = n;
			}

			temp = temp->m[ch];
		}

		temp->isTerminal = true;
	}

	bool search(string word){
		node* temp = root;

		for(auto ch:word){
			if(temp->m.count(ch) == 0) return false;
			else temp = temp->m[ch];
		}

		return temp->isTerminal;
	}
};


int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	vector<string> words = {"apple","mango","news","new","banana"};
	vector<string> queries = {"new","bob","mango","ape"};

	Trie* t = new Trie();

	for(auto word : words){
		t->insert(word);
	}

	for(auto q:queries){
		if(t->search(q)){
			cout<<"Present"<<endl;
		}else{
			cout<<"Not Present"<<endl;
		}
	}


	return 0;
}