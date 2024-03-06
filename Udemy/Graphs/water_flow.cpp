#include<bits/stdc++.h>
using namespace std;


int bfs(int grid[][1001],int rows, int cols){

	bool blueLake[rows][cols];
	bool redLake[rows][cols];

	bool visited[rows][cols];

	memset(blueLake,false,sizeof blueLake);
	memset(redLake,false,sizeof redLake);
	memset(visited,false,sizeof visited);

	queue<pair<int,int>>q;

	for(int i=0;i<rows;i++){
		blueLake[i][0] = true;
		q.push({i,0});
		visited[i][0] = true;
	}

	for(int j=0;j<cols;j++){
		blueLake[0][j] = true;
		q.push({0,j});
		visited[0][j] = true;
	}

	//make bfs for blue lake
	while(!q.empty()){
		pair<int,int>p = q.front();
		q.pop();

		int cx = p.first;
		int cy = p.second;

		int currHeight = grid[cx][cy];

		int dx[] = {1,-1,0,0};
		int dy[] = {0,0,1,-1};

		for(int k=0;k<4;k++){
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if(nx>=0 and ny>=0 and nx<rows and ny<cols and !visited[nx][ny] and grid[nx][ny]>=currHeight){
				q.push({nx,ny});
				visited[nx][ny] = true;
				blueLake[nx][ny] = true;
			}
		}

	}

	memset(visited,false,sizeof visited);

	for(int i=0;i<rows;i++){
		redLake[i][cols-1] = true;
		q.push({i,cols-1});
		visited[i][cols-1] = true;
	}
	for(int j=0;j<cols;j++){
		redLake[rows-1][j] = true;
		q.push({rows-1,j});
		visited[rows-1][j] = true;
	}

	//make bfs for red lake
	while(!q.empty()){
		pair<int,int>p = q.front();
		q.pop();

		int cx = p.first;
		int cy = p.second;

		int currHeight = grid[cx][cy];

		int dx[] = {1,-1,0,0};
		int dy[] = {0,0,1,-1};

		for(int k=0;k<4;k++){
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if(nx>=0 and ny>=0 and nx<rows and ny<cols and !visited[nx][ny] and grid[nx][ny]>=currHeight){
				q.push({nx,ny});
				visited[nx][ny] = true;
				redLake[nx][ny] = true;
			}
		}

	}

	int ans = 0;

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(blueLake[i][j] and redLake[i][j])ans++;
		}
	}

	return ans;
}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int rows,cols;
	cin>>rows>>cols;

	int grid[1001][1001];

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			int x;
			cin>>x;

			grid[i][j] = x;
		}
	}

	cout<<bfs(grid,rows,cols)<<endl;


	return 0;
}