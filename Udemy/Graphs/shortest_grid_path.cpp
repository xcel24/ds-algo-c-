#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int x;
	int y;
	int dist;

	Node(int x,int y, int dist){
		this->x = x;
		this->y = y;
		this->dist = dist;
	}
};

class Compare{
public:
	bool operator()(const pair<int,pair<int,int>>&a, const pair<int,pair<int,int>>&b){
		return a.first <= b.first;
	}
};

int shortestGridPath(vector<vector<int>>&grid){

	int m = grid.size();
	int n = grid[0].size();

	vector<vector<int>>distance(m+1,vector<int>(n+1,INT_MAX));
	set<pair<int,pair<int,int>>>s;

	distance[0][0] = grid[0][0];
	s.insert({distance[0][0],{0,0}});

	while(!s.empty()){
		auto it = s.begin();

		int cx = it->second.first;
		int cy = it->second.second;
		int distanceTillNow = it->first;


		cout<<cx <<" "<<cy<<" "<<distanceTillNow<<" "<<endl;

		s.erase(it);

		int dx[] = {1,-1,0,0};
		int dy[] = {0,0,1,-1};

		for(int k=0;k<4;k++){
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if(nx>=0 and ny>=0 and nx<m and ny<n and distanceTillNow + grid[nx][ny] < distance[nx][ny]){

				if(s.find({distance[nx][ny],{nx,ny}}) != s.end()){
					s.erase(s.find({distance[nx][ny],{nx,ny}}));
				}

				distance[nx][ny] = distanceTillNow + grid[nx][ny];
				s.insert({distance[nx][ny],{nx,ny}});
			}

		}
	}

	return distance[m-1][n-1];
}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int rows,cols;
	cin>>rows>>cols;

	vector<vector<int>>grid(rows*cols);

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			int x;
			cin>>x;

			grid[i].push_back(x);
		}
	}

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<shortestGridPath(grid)<<endl;


	return 0;
}