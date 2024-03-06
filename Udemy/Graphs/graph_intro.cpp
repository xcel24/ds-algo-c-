#include<bits/stdc++.h>
using namespace std;

class Graph{
	//vertices
	int V;
	list<int>* l;

public:
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int i, int j, bool undir = true){
		l[i].push_back(j);
		
		if(undir){
			l[j].push_back(i);
		}

		return;
	}

	void printAdjList(){
		for(int i=0;i<V;i++){
			cout<<i<<"-->"<<" ";

			for(auto node:l[i]){
				cout<<node<<",";
			}
			cout<<endl;
		}

		return;
	}


};

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	//number of vertices
	int v,e;
	cin>>v>>e;

	Graph g(v);

	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;

		g.addEdge(x,y);
	}

	g.printAdjList();


	return 0;
}