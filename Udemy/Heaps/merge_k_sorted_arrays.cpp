#include<bits/stdc++.h>
using namespace std;

vector<int>mergeKSortedArrays(vector<vector<int>>numbers){

	//element, array index, element idx
	priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
	vector<int>ans;

	int k = numbers.size();
	for(int i=0;i<k;i++){
		pq.push({numbers[i][0],i,0});
	}

	while(!pq.empty()){
		auto top = pq.top();
		pq.pop();

		int element = top[0];
		int array_idx = top[1];
		int element_idx = top[2];

		ans.push_back(element);

		if(element_idx + 1 < numbers[array_idx].size()){
			pq.push({numbers[array_idx][element_idx + 1],array_idx,element_idx + 1});
		}
	}

	return ans;
}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n;
	cin>>n;

	vector<vector<int>>numbers;

	for(int i=0;i<n;i++){
		int k;
		cin>>k;

		vector<int>temp;
		for(int i=0;i<k;i++){
			int x;
			cin>>x;

			temp.push_back(x);
		}

		numbers.push_back(temp);
	}

	for(auto x: mergeKSortedArrays(numbers)){
		cout<<x<<" ";
	}

	return 0;
}