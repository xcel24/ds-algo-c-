#include<bits/stdc++.h>
using namespace std;

class Graph{
    int vertices;
    unordered_map<int,vector<int>>connections;
    
    public:
        Graph(int v){
            vertices = v;
        }
        
        void addEdge(int x,int y){
            connections[x].push_back(y);
            
            return;
        }

        void printAdj(){
			for(auto i:connections){
				cout<<i.first<<"-->";
				for(auto j:i.second) cout<<j<<" ";
				cout<<endl;
			}
		}
        
        int bfs(int source, int destination){
            queue<int>q;
            bool* visited = new bool[vertices]{false};
            int* distance = new int[vertices]{-1};
            
            q.push(source);
            visited[source] = true;
            distance[source] = 0;
            
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                
                for(auto nbr:connections[curr]){
                    if(!visited[nbr]){
                        visited[nbr] = true;
                        distance[nbr] = 1 + distance[curr];
                    }
                }
            }
            
            return distance[destination];
        }
};

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int board[101] = {0};

	vector<vector<int>>ladders = {
		{3,90}
	};

	vector<vector<int>>snakes = {
		{99,10},
		{97,20},
		{98,30},
		{96,40},
		{95,50},
		{94,60},
		{93,70}
	};
    //add ladders
    for(auto ladder:ladders){
        int start = ladder[0];
        int end = ladder[1];
        
        board[start] = end - start;
    }
    
    //add snakes
    for(auto snake:snakes){
        int start = snake[0];
        int end = snake[1];
        
        board[start] = end - start;
    }
    
    Graph g(100);
    
    for(int i=1;i<100;i++){
        for(int dice = 1;dice<=6;dice++){
            int v = i + dice;
            
            if(v<100){
            	v += board[v];
                g.addEdge(i,v);
            }
            
        }
    }

    g.printAdj();
    
    int distance = g.bfs(1,100);

    cout<<distance<<endl;


	return 0;
}