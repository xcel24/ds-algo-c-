#include<bits/stdc++.h>
using namespace std;

class Car{
public:
	string name;
	int x;
	int y;

	Car(string name, int x, int y){
		this->name = name;
		this->x = x;
		this->y = y;
	}

	int dist() const {
		return x*x + y*y;
	}
};

class CarCompare{
public:
	bool operator()(const Car A, const Car B){
		return A.dist() > B.dist();
	}
};

void printKNearestCars(vector<Car>&cars,int k){

	//let's build a max heap of size k
	priority_queue<Car,vector<Car>,CarCompare> pq(cars.begin(),cars.begin() + k);

	for(int i=k;i<cars.size();i++){
		if(pq.top().dist() > cars[i].dist()){
			 pq.pop();
			 pq.push(cars[i]);
		}
	}	

	cout<<"K nearest cars are"<<endl;

	while(!pq.empty()){
		Car curr = pq.top();

		cout<<curr.name<<"-->"<<curr.dist()<<endl;;

		pq.pop();
	}

	return;

}



int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n,k;
	cin>>n>>k;

	string name;
	int x,y;

	vector<Car>cars;

	for(int i=0;i<n;i++){
		cin>>name>>x>>y;

		Car car(name,x,y);

		cars.push_back(car);
	}

	printKNearestCars(cars,k);



	return 0;
}
