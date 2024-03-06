#include<bits/stdc++.h>
using namespace std;

int pickFromBoth(vector<int>arr,int B){
	
	int n = arr.size();

	vector<int>left(n,0);
	vector<int>right(n,0);

	left[0] = arr[0];
	right[n-1] = arr[n-1];

	for(int i=1;i<n;i++){
		left[i] = left[i-1] + arr[i];
		right[n-1-i] = right[n-i] + arr[n-1-i];
	}

	int ans=-1;
	
	while(B>0){
		int op1 = 
	}


	return 0;
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

	int B;
	cin>>B;

	cout<<pickFromBoth(arr,B);

	return 0;
}