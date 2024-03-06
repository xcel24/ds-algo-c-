#include<bits/stdc++.h>
using namespace std;

void printBoard(int board[][20],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(board[i][j]==1){
				cout<<"Q"<<" ";	
			}
			else{
				cout<<"*"<<" ";
			}
			
		}
		cout<<endl;
	}

	cout<<endl;
}

bool canPlace(int board[][20],int n,int x,int y){

	//check column
	for(int k=0;k<x;k++){
		if(board[k][y]==1){
			return false;
		}
	}

	//check left diagonal
	int i = x;
	int j = y;

	while(i>=0 and j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--;
		j--;
	}

	i=x;
	j=y;

	//check right diagonal
	while(i>=0 and j<n){
		if(board[i][j]==1){
			return false;
		}

		i--;
		j++;
	}

	return true;

}

bool solveNQueen(int board[][20], int n, int i){

	//base case
	if(i == n){

		printBoard(board, n);

		return true;
	}

	//recursive case
	for(int j=0;j<n;j++){

		//check whether it is safe to place the queen
		if(canPlace(board,n,i,j)){

			board[i][j] = 1;
			solveNQueen(board,n,i+1);

			// if(success){
			// 	return true;
			// }

			board[i][j] = 0;
		}
	}

	return false;

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif
	
	int board[20][20] = {};
	int n;
	cin>>n;

	solveNQueen(board, n, 0);

	// if(!ans){
	// 	cout<<"No possible configuration"<<endl;
	// }


	return 0;
}