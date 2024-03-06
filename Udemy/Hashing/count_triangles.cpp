#include<bits/stdc++.h>
using namespace std;

class Point{
public:
	int x;
	int y;

	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
};


int countTriangles(vector<Point>&points){

	unordered_map<int,int>x_store, y_store;

	for(Point p: points){
		x_store[p.x]++;
		y_store[p.y]++;
	}

	int ans = 0;

	for(Point p:points){

		int a = x_store[p.x];
		int b = y_store[p.y];

		if(a >=1 and b>=1){
			ans += (a-1) * (b-1);
		}
	}

	return ans;
}



int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	vector<Point>points;

	int x, y;

	for(int i=0;i<n;i++){
		cin>>x>>y;

		Point p(x,y);
		points.push_back(p);

	}

	cout<<countTriangles(points)<<endl;

	return 0;
}