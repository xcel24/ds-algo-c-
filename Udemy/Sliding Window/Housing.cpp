#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> getHouseAreas(vector<int>areas,int k){

	int left=0,right=0;
	int n=areas.size();

	int curr=0;

	vector<pair<int,int>>ans;

	while(right<n){

		//expansion
		curr+=areas[right];
		right++;

		//contraction
		while(curr>k and left<right){
			curr=curr-areas[left];
			left++;
		}

		//if equal
		if(curr==k){  
			ans.push_back({left,right-1});
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

	vector<int>areas;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;

		areas.push_back(tmp);
	}

	int k;
	cin>>k;

	vector<pair<int,int>> ans = getHouseAreas(areas,k);

	for(auto p:ans){
		cout<<p.first<<","<<p.second<<endl;
	}


	return 0;
}