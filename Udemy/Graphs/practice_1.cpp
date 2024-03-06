#include<bits/stdc++.h>
using namespace std;

class Graph{
	int vertices;
	vector<int>* connections;

public:
	Graph(int v){
		vertices = v;
		connections = new vector<int>[vertices];
	}

	void addEdge(int x, int y){
		connections[x].push_back(y);
	}

	bool dfs(int source,bool* visited, bool* stack){
		visited[source] = true;
		stack[source] = true;

		for(auto nbr:connections[source]){
			if(visited[nbr] and stack[nbr]) return true;
			else if(visited[nbr] == false){
				bool nbrFoundACycle = dfs(nbr,visited,stack);

				if(nbrFoundACycle) return true;
			}
		}

		stack[source] = false;

		return false;
	}

	bool detectCycle(){
		bool* visited = new bool[vertices]{false};
		bool* stack = new bool[vertices]{false};

		for(int i=0;i<vertices;i++){
			if(dfs(i,visited,stack)) return true;
		}

		return false;
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

	if(g.detectCycle())cout<<"Cycle Present"<<endl;
	else cout<<"Cycle not Present"<<endl;


	return 0;
}