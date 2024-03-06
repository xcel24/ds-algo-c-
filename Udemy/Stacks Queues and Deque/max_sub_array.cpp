#include<bits/stdc++.h>
using namespace std;

int maxInWindow(vector<int>arr,int left,int right,int max_till_far){
	if(max_till_far== ){
		for(int i=left;i<=right;i++){
			max_till_far = max(arr[i],max_till_far);
		}
	}else{
		max_till_far = max(max_till_far,arr[right]);
	}

	return max_till_far;
}


vector<int>maxSubarray(vector<int>arr,int k){

	int left = 0;
	int right = left + k-1;

	int n = arr.size();

	int max_till_far = INT_MIN;
	vector<int> ans;

	while(right < n){
		int temp = maxInWindow(arr,left,right,max_till_far);
		max_till_far = max(max_till_far,temp);
		ans.push_back(max_till_far);

		//increment right
		right++;
		left++;

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


	vector<int>ans = maxSubarray(arr,k);

	for(auto x:ans){
		cout<<x<<endl;
	}


	return 0;
}