#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
	int V;
	list<int>* l;

	Graph(int v){
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int x,int y,bool undir = true){
		l[x].push_back(y);
		if(undir){
			l[y].push_back(x);
		}
	}

	void bfs(int source,int des = -1){
		queue<pair<int,int>>q;
		bool *visited = new bool[V]{0};
		int* parent = new int[V]{-1};

		q.push({source,0});
		q.push({-1,-1});
		visited[source] = true;
		parent[source] = source;

		while(!q.empty()){
			pair<int,int> curr = q.front();
			q.pop();

			if(curr.first == -1){
				cout<<endl;

				if(!q.empty()){
					q.push({-1,-1});
				}
			}else{
				cout<<curr.first<<","<<curr.second<<" ";
				for(auto nbr:l[curr.first]){
					if(!visited[nbr]){
						q.push({nbr,curr.second + 1});
						visited[nbr] = true;
						parent[nbr] = curr.first;
					}
				}
			}
		}

		cout<<endl;

		if(des !=-1){
			int temp = des;

			while(temp != source){
				cout<<temp<<"-->";
				temp = parent[temp];
			}

			cout<<source<<"-->";

			cout<<endl;
		}

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

	g.bfs(1,6);


	return 0;
}