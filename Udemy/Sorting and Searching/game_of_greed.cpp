#include<bits/stdc++.h>
using namespace std;

bool canPartitionArray(vector<int>&coins, int k, int val){

	int f = 0;
	int curr_val = 0;
	for(int i=0; i<coins.size();i++){
		curr_val += coins[i];
		

		if(curr_val >= val){
			f++;
			curr_val = 0;

			if(f==k){
				return true;
			}
		}
	}

	return false;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n,k;
	cin>>n>>k;

	vector<int>coins;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		coins.push_back(x);
	}

	//sort the coins array first
	sort(coins.begin(),coins.end());

	int s = coins[0];
	int e = 0;
	for(auto c:coins){
		e += c;
	}

	int ans = -1;

	//game of greed algo
	while(s <= e){
		int mid = (s+e)/2;

		bool canPartition = canPartitionArray(coins, k, mid);
		if(canPartition){
			s = mid + 1;
			ans = mid;
		}else {
			e = mid - 1;
		}
	}

	cout<<ans<<endl;


	return 0;
}