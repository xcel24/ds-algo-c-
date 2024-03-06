#include<bits/stdc++.h>
using namespace std;

class Graph{
	int vertices;
	vector<pair<int,int>>*connections;

public:
	Graph(int v){
		vertices = v;
		connections = new vector<pair<int,int>>[vertices];
	}

	void addEdge(int x, int y, int weight, bool undir = true){
		connections[x].push_back({y,weight});

		if(undir){
			connections[y].push_back({x,weight});
		}

		return;
	}

	void printAdj(){
		for(int i=0;i<vertices;i++){
			cout<<i<<"-->";
			for(int j=0;j<connections[i].size();j++){
				cout<<"[ "<<connections[i][j].first<<","<<connections[i][j].second<<" ]";
			}
			cout<<endl;
		}

		return;
	}

	void dfsHelper(int source, bool*visited){
		visited[source] = true;

		cout<<source<<" ";
		for(auto nbr:connections[source]){
			if(!visited[nbr.first]){
				dfsHelper(nbr.first,visited);
			}
		}

		return;
	}

	void dfs(int source){
		bool* visited = new bool[vertices]{false};

		dfsHelper(source,visited);
		cout<<endl;
	}

	void bfs(int source){
		queue<int>q;
		bool* visited = new bool[vertices]{false};

		q.push(source);
		visited[source] = true;

		while(!q.empty()){
			int curr = q.front();
			q.pop();

			cout<<curr<<" ";

			for(auto nbr:connections[curr]){
				if(!visited[nbr.first]){
					visited[nbr.first] = true;
					q.push(nbr.first);
				}
			}
		}

		cout<<endl;
		return;
	}

	int dijkstra(int source){
		vector<int>distance(vertices,INT_MAX);
		set<pair<int,int>>s;

		distance[source] = 0;
		s.insert({source,distance[source]});

		while(!s.empty()){
			auto it = s.begin();

			int currNode = it->first;
			int distanceTillNow = it->second;

			s.erase(it);

			for(auto nbr:connections[currNode]){
				int newNode = nbr.first;
				int weight = nbr.second;

				auto f = s.find({newNode,weight});

				if(f != s.end()){
					s.erase(f);
				}

				if(distanceTillNow + weight < distance[newNode]){
					distance[newNode] = distanceTillNow + weight;
					s.insert({newNode,distance[newNode]});
				}
			}
		}

		cout<<"Shortest distance of each node from source is"<<endl;

		for(int i=0;i<distance.size();i++){
			cout<<i<<"-->"<<distance[i]<<" Km"<<endl;
		}

		return distance[distance.size()-1];
	}

	bool detectCycleHelper(int source, bool* visited,int parent){
		visited[source] = true;

		for(auto nbr:connections[source]){
			if(!visited[nbr.first]){
				bool nbrFoundACycle = detectCycleHelper(nbr.first,visited,source);

				if(nbrFoundACycle) return true;
			}else{
				if(nbr.first != parent) return true;
			}
		}

		return false;
	}

	bool detectCycle(int source){
		bool* visited = new bool[vertices]{false};

		return detectCycleHelper(source,visited,source);
	}
};

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int v,e;
	cin>>v>>e;

	Graph g(v);

	for(int i=0;i<e;i++){
		int x,y,w;
		cin>>x>>y>>w;

		g.addEdge(x,y,w);
	}

	g.printAdj();

	cout<<"-------------"<<endl;

	g.dfs(0);
	cout<<"--------------"<<endl;
	g.bfs(0);
	cout<<"--------------"<<endl;

	cout<<g.dijkstra(0)<<endl;

	if(g.detectCycle(0))cout<<"Cycle Present"<<endl;
	else cout<<"Cycle not Present"<<endl;

	return 0;
}