#include<bits/stdc++.h>
using namespace std;

class Point{
public:
	int x;
	int y;

	Point(){

	}

	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
};

class Compare{
public:
	bool operator()(const Point p1, const Point p2){
		if(p1.x == p2.x){
			return p1.y < p2.y;
		}

		return p1.x < p2.x;
	}
};


int countRectangles(vector<Point>&points){

	//step 1 is to insert all the points in the set
	set<Point, Compare>s;

	for(Point p:points){
		s.insert(p);
	}

	int ans = 0;

	// step 2 is to brute force the 2 points and look up the remaining 2 points
	// prev is used to go to the second last element
	// next is usec to start from the next of whatever the value it is pointing to
	for(auto it = s.begin(); it != prev(s.end());it++){
		for(auto jt = next(it); jt != s.end(); jt++){

			Point p1 = *it;
			Point p2 = *jt;

			//we weill make a check that the 2 points should not be lying on the same x and y axis
			if(p1.x == p2.x or p1.y == p2.y){
				continue;
			}

			Point p3(p1.x, p2.y);
			Point p4(p2.x, p1.y);

			if(s.find(p3) != s.end() and s.find(p4) != s.end()){
				ans += 1;
			}

		}
	}

	return ans/2;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	vector<Point> points;
	int x,y;

	for(int i=0;i<n;i++){
		cin>>x>>y;

		Point p(x,y);
		points.push_back(p);
	}

	cout<<countRectangles(points)<<endl;

	return 0;
}