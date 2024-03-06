#include<bits/stdc++.h>
using namespace std;

void captureRegion(vector<vector<char>>&board){

	int rows= board.size();
	int cols = board[0].size();

	vector<vector<bool>>visited(rows,vector<bool>(cols,false));

	queue<pair<int,int>>q;

	//insert the top row 
	for(int j=0;j<cols;j++){
		if(board[0][j] == 'O' and !visited[0][j]){
			q.push({0,j});
		}
	}

	//insert the left row
	for(int i=0;i<rows;i++){
		if(board[i][0] == 'O' and !visited[i][0]){
			q.push({i,0});
		}
	}

	//insert the bottom row
	for(int j=0;j<cols;j++){
		if(board[rows-1][j] == 'O' and !visited[rows-1][j]){
			q.push({rows-1,j});
		}
	}

	//insert the right row
	for(int i=0;i<rows;i++){
		if(board[i][cols-1] == 'O' and !visited[i][cols-1]){
			q.push({i,cols-1});
		}
	}

	//make bfs call on this queue
	while(!q.empty()){
		pair<int,int>curr = q.front();
		q.pop();

		int cx = curr.first;
		int cy = curr.second;

		visited[cx][cy] = true;

		//directions
		int dx[] = {1,-1,0,0};
		int dy[] = {0,0,1,-1};

		for(int k=0;k<4;k++){
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if(nx>=0 and ny>=0 and nx<rows and ny<cols and board[nx][ny] == 'O' and !visited[nx][ny]){
				q.push({nx,ny});
				visited[nx][ny] = true;
			}
		}
	}

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(board[i][j]== 'O' and !visited[i][j]){
				board[i][j] = 'X';
			}
		}
	}

	return;	
}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int rows,cols;
	cin>>rows>>cols;

	vector<vector<char>>board(rows,vector<char>(cols));

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			char ch;
			cin>>ch;

			board[i][j] = ch;
		}
	}

	captureRegion(board);

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}