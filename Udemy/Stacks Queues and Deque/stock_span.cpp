#include<bits/stdc++.h>
using namespace std;

vector<int>stockSpan(vector<int>&arr){
	int n = arr.size();

	stack<int>s;

	vector<int>span(n,1);

	for(int i=0;i<n;i++){

		while(!s.empty() and arr[s.top()] <= arr[i]){
			span[i] += span[s.top()];
			s.pop();
		}

		s.push(i);
	}

	return span;
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

	vector<int> ans = stockSpan(arr);
	for(auto x:ans){
		cout<<x<<" ,";
	}
	cout<<endl;


	return 0;
}