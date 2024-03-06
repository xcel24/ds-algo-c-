#include<bits/stdc++.h>
using namespace std;

bool canPlace(int matrix[][9],int row,int col,int num){

	//check if this number is avaialble in the row
	for(int j=0;j<9;j++){
		if(matrix[row][j]==num || matrix[j][col]==num){
			return false;
		}
	}

	//check for subgrid
	int sx = (row/3) * 3;
	int sy= (col/3) * 3;

	for(int x=sx;x<sx+3;x++){
		for(int y=sy;y<sy+3;y++){
			if(matrix[x][y]==num){
				return false;
			}
		}
	}


	return true;


}


bool solveSudoku(int matrix[][9],int i,int j,int n){

	//base case
	if(i==n){

		return true;
	}

	//recursive case
	
	if(j==n){
		return solveSudoku(matrix,i+1,0,9);
	}

	//skip the prefilled cells
	if(matrix[i][j] != 0){
		return solveSudoku(matrix,i,j+1,9);
	}

	for(int num=1;num<=9;num++){
		if(canPlace(matrix,i,j,num)){
			matrix[i][j] = num;
			bool success = solveSudoku(matrix,i,j+1,9);

			if(success){
				return true;
			}

			
		}
	}

	matrix[i][j] = 0;
	return false;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int matrix[9][9]={
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
	};


	if(!solveSudoku(matrix,0,0,9)){
		cout<<"No solution exists"<<endl;
	}else{
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	return 0;
}