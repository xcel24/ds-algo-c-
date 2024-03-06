#include<bits/stdc++.h>
using namespace std;

int getLowerValue(set<int>&s,int value){
	auto it = s.lower_bound(value);

	--it;

	return *it;
}


int maximumSumTriplet(vector<int>&A,int n){

	int right[n];


	right[n-1] = A[n-1];

	for(int i=n-2;i>=0;i--){
		right[i] = max(right[i+1],A[i]);
	}

	int ans = 0;

	set<int>s;
	s.insert(INT_MIN);

	for(int i=0;i<n-1;i++){
		int sum = A[i] + right[i+1] + getLowerValue(s,A[i]);
		ans = max(ans,sum);

		s.insert(A[i]);
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

	cout<<maximumSumTriplet(arr,n)<<endl;


	return 0;
}