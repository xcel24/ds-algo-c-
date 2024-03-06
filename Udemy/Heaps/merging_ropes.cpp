#include<bits/stdc++.h>
using namespace std;

int mergeRopes(vector<int>&ropes){

	//step 1 push all element is heap
	priority_queue<int,vector<int>,greater<int>>pq;

	for(auto x:ropes){
		pq.push(x);
	}

	int cost = 0;

	while(pq.size() > 1){
		int r1 = pq.top();
		pq.pop();

		int r2 = pq.top();
		pq.pop();

		cost += r1 + r2;

		pq.push(r1 + r2);
	}

	return cost;
}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n;
	cin>>n;

	vector<int>ropes;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		ropes.push_back(x);
	}

	cout<<mergeRopes(ropes)<<endl;


	return 0;
}