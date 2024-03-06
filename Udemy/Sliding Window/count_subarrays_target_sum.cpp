#include<bits/stdc++.h>
using namespace std;

int subarrayTargetSum(vector<int>arr,int k){

	unordered_map<int,int>m;
	int ans=0;
	int curr_sum=0;

	for(int i=0;i<arr.size();i++){

		curr_sum = curr_sum + arr[i];

		if(curr_sum==k){
			ans++;
		}

		if(m.find(curr_sum-k) != m.end()){
			ans+=m[curr_sum-k];
		}

		m[curr_sum]++;

	}

	return ans;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif
	int n,k;
	cin>>n>>k;

	vector<int>arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		arr.push_back(x);
	}

	cout<<subarrayTargetSum(arr,k)<<endl;



	return 0;
}