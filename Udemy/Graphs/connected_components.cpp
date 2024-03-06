#include<bits/stdc++.h>
using namespace std;

class Graph{
	int vertices;
	vector<int>*connections;

public:
	Graph(int v){
		vertices = v;
		connections = new vector<int>[vertices + 1];
	}

	void addEdge(int u,int v){
		connections[u].push_back(v);
		connections[v].push_back(u);

		return;
	}

	void dfs(int source,vector<bool>&visited){
		if(visited[source]) return;

		visited[source] = true;

		for(auto nbr:connections[source]){
			if(!visited[nbr]){
				dfs(nbr,visited);
			}
		}

		return;
	}

	int connectedComponents(){
		vector<bool>visited(vertices + 1, false);

		int cnt = 0;

		for(int i=1;i<=vertices;i++){
			if(!visited[i]){
				dfs(i,visited);
				cnt++;
			}
		}

		return cnt;
	}
};

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n,m;
	cin>>n>>m;

	Graph g(n);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;

		g.addEdge(x,y);
	}

	cout<<g.connectedComponents()<<endl;

	return 0;
}