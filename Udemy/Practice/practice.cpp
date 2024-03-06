#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>arr){
	int n = arr.size();

	pair<int,int>store[n];

	for(int i=0;i<n;i++){
		store[i].first = arr[i];
		store[i].second = i;
	}

	//sort
	sort(store,store+n);

	vector<bool> visited(n,false);
	int ans = 0;

	for(int i=0;i<n;i++){

		int old_pos = store[i].second;

		if(visited[i] == true or old_pos==i){
			continue;
		}

		int cycle = 0;
		int node = i;
		while(!visited[node]){
			visited[node] = true;
			int next_node = store[node].second;
			cycle += 1;

			node = next_node;
		}

		ans += (cycle-1);
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

	vector<int>arr;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		arr.push_back(x);
	}


	cout<<minSwaps(arr)<<endl;

	return 0;
}