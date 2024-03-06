#include<bits/stdc++.h>
using namespace std;

struct ComparePairs {
    bool operator()(const pair<pair<int,int>, int>& p1, const pair<pair<int,int>, int>& p2) const {
      return p1.second < p2.second;
  }
};

int djikstra(vector<vector<int>>&grid){
	//step 1 is assume all distances are at infinity from the source

	int rowSize = grid.size();
	int colSize = grid[0].size();

	vector<vector<int>>distance(rowSize + 1,vector<int>(colSize + 1,INT_MAX));
	vector<vector<bool>>visited(rowSize + 1,vector<bool>(colSize + 1,false));
	set<pair<pair<int,int>,int>, ComparePairs> s;

	distance[0][0] = grid[0][0];
	s.insert({{0,0},distance[0][0]});


	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,1,-1};

	while(!s.empty()){
		auto it = s.begin();

		int cx = it->first.first;
		int cy = it->first.second;
		int distanceTillNow = it->second;

		s.erase(it);

		for(int k=0;k<4;k++){
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			cout<<"nx is "<<nx<<" and ny is "<<ny<<endl;


			if(nx>=0 and ny>=0 and nx<rowSize and ny<colSize){
				auto f = s.find({{nx,ny},distance[nx][ny]});

				if(f != s.end()){
					s.erase(f);
				}

				if(distanceTillNow + grid[nx][ny] < distance[nx][ny]){
					distance[nx][ny] = distanceTillNow + grid[nx][ny];

					cout<<distance[nx][ny]<<endl;

					s.insert({{nx,ny},distance[nx][ny]});
				}
			}
		}
	}

	return distance[rowSize-1][colSize-1];

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

	cout<<djikstra(grid)<<endl;

	return 0;
}