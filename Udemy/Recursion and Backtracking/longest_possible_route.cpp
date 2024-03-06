#include<bits/stdc++.h>
using namespace std;

int globalMax = INT_MIN;

int findLongestPath(int maze[][10], int n, int row, int col, bool visited[][10],
	int &left,int &right,int &up,int &down){

	//base case
	if(row>=n or col >=n) return false;
	if(row == n-1 and col == n-1){
		return true;
	}

	//recursive case

	//moving towards right
	if(canMove(maze,n,row,col,visited)){
		visited[row][col+1] = true;
		bool success = findLongestPath(maze,n,row,col+1,visited,left,right,up,down);
		if(success){
			right += 1;
		}
	}



}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int maze[10][10] = {
		{1,1,1},
		{1,1,1},
		{0,0,1}
	};

	int n = 3;

	bool visited [10][10] = {false};

	int left = 0,right=0,up=0,down=0;

	cout<<findLongestPath(maze,n,0,0,visited,left,right,up,down)<<endl;

	return 0;
}