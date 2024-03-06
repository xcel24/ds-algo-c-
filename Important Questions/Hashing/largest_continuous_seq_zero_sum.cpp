#include<bits/stdc++.h>
using namespace std;

vector<int> largestSequence(vector<int>arr){

	unordered_map<int,int>m;

	int sum = 0, max_left = 0, max_right = 0, max_ans = 0;

	for(int i=0;i<arr.size();i++){

		sum += arr[i];

		if(m.find(sum) != m.end()){

			if(max_ans < i - m[sum]){
				max_ans = i - m[sum];
				max_left = m[sum];
				max_right = i;
			}

		}else{
			m[sum] = i;
		}

	}

	vector<int>ans;
	for(int i=max_left+1;i<=max_right;i++){
		ans.push_back(arr[i]);
	}

	return ans;

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif


	vector<int>arr = {1,2,-2,4,-4};

	vector<int>ans = largestSequence(arr);

	for(auto x:ans){
		cout<<x<<" ";
	}

	cout<<endl;

	return 0;
}