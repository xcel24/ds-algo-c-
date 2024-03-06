#include<bits/stdc++.h>
using namespace std;

int findSubsets(vector<int>arr,int start,int target){

	//base case
	if(start == arr.size()){
		if(target==0){
			return 1;
		}
		else return 0;
	}

	//recursive case

	return findSubsets(arr,start+1,target-arr[start]) + findSubsets(arr,start+1,target);

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n,target;
	cin>>n>>target;

	vector<int>arr;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		arr.push_back(x);
	}

	cout<<findSubsets(arr,0,target)<<endl;


	return 0;
}