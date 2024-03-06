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

	void addEdge(int x,int y){
		l[x].push_back(y);
	}

	bool dfs(int node,vector<bool>&visited,vector<bool>&stack){
		visited[node] = true;
		stack[node] = true;

		for(auto nbr:l[node]){
			if(stack[nbr] == true) return true;
			else if(visited[nbr] == false){
				bool nbrFoundACycle = dfs(nbr,visited,stack);
				if(nbrFoundACycle) return true;
			}
		}

		stack[node] = false;
		return false;
	}

	bool detectCycle(){
		vector<bool>visited(V,false);
		vector<bool>stack(V,false);

		for(int i=0;i<V;i++){
			if(!visited[i]){
				if(dfs(i,visited,stack)) return true;
			}
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


	if(g.detectCycle()) cout<<"Cycle present"<<endl;
	else cout<<"Cycle not present"<<endl;


	return 0;
}