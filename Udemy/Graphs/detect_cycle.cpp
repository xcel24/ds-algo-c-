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
	void addEdge(int x, int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool dfs(int source,vector<bool>&visited,int parent){
		visited[source] = true;

		for(auto nbr:l[source]){
			if(!visited[nbr]){
				bool nbrFoundCycle = dfs(nbr,visited,source);

				if(nbrFoundCycle) return true;
			}else if(nbr != parent) return true;
		}

		return false;
	}

	bool detectCycle(int source){
		vector<bool>visited(V,false);

		return dfs(source,visited,-1);
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

	if(g.detectCycle(0)) cout<<"Cycle present"<<endl;
	else cout<<"Cycle not present"<<endl;	


	return 0;
}