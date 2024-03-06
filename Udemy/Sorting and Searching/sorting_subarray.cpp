#include<bits/stdc++.h>
using namespace std;

pair<int,int>sortingSubarray(vector<int>arr){

	int n = arr.size();
	int s=0;
	int e = n-1;

	for(s=0;s<n-1;s++){
		if(arr[s]>arr[s+1]){
			break;
		}
	}

	//means array is completely sorted

	if(s==n-1){
		return {-1,-1};
	}

	for(e=n-1;e>0;e--){
		if(arr[e]<arr[e-1]){
			break;
		}
	}

	int minima,maxima;
	minima = arr[s];
	maxima = arr[s];

	for(int i=s+1;i<=e;i++){
		minima = min(minima,arr[i]);
		maxima = max(maxima,arr[i]);
	}

	for(int i=0;i<s;i++){
		if(arr[i]>minima){
			s = i;
			break;
		}
	}

	for(int i=n-1;i>e;i--){
		if(arr[i]<maxima){
			e=i;
			break;
		}
	}

	return {s,e};

	

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

	pair<int,int>ans = sortingSubarray(arr);

	cout<<ans.first<<","<<ans.second<<endl;


	return 0;
}