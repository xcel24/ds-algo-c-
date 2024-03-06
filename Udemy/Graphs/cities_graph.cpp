#include<bits/stdc++.h>
using namespace std;

class Node{

public:
	string name;
	list<string> nbrs;
	Node(string name){
		this->name = name;
	}
};

class Graph{
	unordered_map<string, Node*>m;

public:
	Graph(vector<string>cities){
		for(auto city:cities){
			m[city] = new Node(city);
		}
	}

	void addEdge(string x, string y, bool undir = false){
		m[x]->nbrs.push_back(y);

		if(undir){
			m[y]->nbrs.push_back(x);
		}
	}

	void printGraph(){
		for(auto x:m){
			cout<<x.first<<"-->";
			for(auto y:x.second->nbrs){
				cout<<y<<",";
			}
			cout<<endl;
		}
	}
};

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int v,e;
	cin>>v>>e;

	vector<string>cities;

	for(int i=0;i<v;i++){
		string city;
		cin>>city;

		cities.push_back(city);
	}

	Graph g(cities);

	for(int i=0;i<e;i++){
		string c1,c2;
		cin>>c1>>c2;

		g.addEdge(c1,c2);
	}

	g.printGraph();



	return 0;
}