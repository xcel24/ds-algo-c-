#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int>* l;

public:
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int x, int y, bool undir = true){
		l[x].push_back(y);

		if(undir){
			l[y].push_back(x);
		}
	}

	void dfsHelper(int source,bool* visited){
		//base case
		if(visited[source]) return;

		//recursive case
		cout<<source<<"-->";
		visited[source] = true;
		for(auto nbr:l[source]){
			if(!visited[nbr]){
				dfsHelper(nbr,visited);

			}
		}
	}


	void dfs(int source){

		bool* visited = new bool[V]{0};

		dfsHelper(source,visited);
	}
};

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int v,e;
	cin>>v>>e;

	Graph g(v);

	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;

		g.addEdge(x,y);
	}

	g.dfs(1);

	return 0;
}