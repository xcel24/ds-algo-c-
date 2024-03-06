#include<bits/stdc++.h>
using namespace std;

void minPairs(vector<int>&arr1,vector<int>&arr2){

	//sort the 1st array
	sort(arr2.begin(),arr2.end());

	int diff = INT_MAX;
	int p1;
	int p2;

	for(auto x:arr1){
		auto lb = lower_bound(arr2.begin(),arr2.end(),x) - arr2.begin();

		//left
		if(lb>=1 and x-arr2[lb-1]<diff){
			diff = x-arr2[lb-1];
			p2 = x;
			p1 = arr2[lb-1];
		}

		//greater right
		if(lb != arr2.size() and arr2[lb]-x < diff){
			diff = arr2[lb]-x;
			p1 = x;
			p2 = arr2[lb];
		}
	}

	cout<<p1<<","<<p2<<endl;

}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n,m;
	cin>>n>>m;

	vector<int>arr1;
	vector<int>arr2;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		arr1.push_back(x);
	}

	for(int i=0;i<m;i++){
		int x;
		cin>>x;

		arr2.push_back(x);
	}

	minPairs(arr1,arr2);


	return 0;
}