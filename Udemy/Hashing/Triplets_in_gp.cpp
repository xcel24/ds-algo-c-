#include<bits/stdc++.h>
using namespace std;

int countTriplets(vector<int>&arr, int r){

	unordered_map<long,long> right, left;

	//initialize right map with freq, and left =0
	for(auto x:arr){
		right[x]++;
		left[x]=0;
	}

	int ans = 0;

	for(int i=0;i<arr.size();i++){

		//step 1 reduce the freq from the right
		right[arr[i]]--;

		//step 2 check whether arr[i]/r is possible or not

		if(arr[i] % r == 0){

			long a = arr[i] / r;
			long c = arr[i] * r;

			ans += left[a] * right[c];
		}

		//step 3 increase the freq of arr[i] in the left
		left[arr[i]]++;

	}

	return ans;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	vector<int> arr = {1,16,4,16,64,16};
	int r = 4;

	cout<<countTriplets(arr, r)<<endl;


	return 0;
}