#include<bits/stdc++.h>
using namespace std;

bool canMove(int maze[][10],int i,int j,int n){

	return maze[i][j] == 1 ? false : true;

}

bool findPathInAMaze(int maze[][10],int i,int j,int n,vector<int>&steps,int values[][10]){

	//base case
	if(i== n-1 and j== n-1){
		return true;
	}

	if(j>n || i>n){
		return false;
	}

	//recursive case

	//taking step right and see if we can reach the end
	if(canMove(maze,i,j+1,n)){
		steps.push_back(values[i][j+1]);
		bool success = findPathInAMaze(maze,i,j+1,n,steps,values);
		if(success){
			return true;
		}
		steps.pop_back();
	}

	//taking step down and see if we can reach the end
	if(canMove(maze,i+1,j,n)){
		steps.push_back(values[i+1][j]);
		bool success =  findPathInAMaze(maze,i+1,j,n,steps,values);
		if(success){
			return true;
		}
		steps.pop_back();
	}

	return false;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int maze[10][10] = {
		{0,0,1,0},
		{0,1,0,0},
		{0,0,0,1},
		{1,1,0,0}
	};

	int values [10][10] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	vector<int>steps;
	steps.push_back(values[0][0]);

	if(findPathInAMaze(maze,0,0,4,steps,values)){
		cout<<"Yes"<<endl;
	}else {
		cout<<"No"<<endl;
	}

	for(auto x: steps){
		cout<<x<<" ";
	}

	return 0;
}