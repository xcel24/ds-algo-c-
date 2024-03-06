#include<bits/stdc++.h>
using namespace std;

vector<int>findSubarray(vector<int>arr){
	vector<int>ans;

	unordered_map<int,int>m;

	int sum = 0;

	int max_ans = 0, max_left = 0, max_right = 0;

	for(int i=0;i<arr.size();i++){

		if(arr[i]==0){
			sum -= 1;
		}else{
			sum +=1;
		}

		if(sum == 1){
			max_ans = i + 1;
			max_right = i;
		}

		if(m.find(sum) == m.end()){
			m[sum] = i;
		}

		if(m.find(sum-1) != m.end()){
			if(max_ans < i - m[sum-1]){
				max_right = i;
				max_left = m[sum-1];
				max_ans = i - m[sum-1];
			}
		}

	}

	for(int i=max_left+1; i<=max_right;i++){
		ans.push_back(arr[i]);
	}

	return ans;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	vector<int>arr = {0,1,1,0,0,1};

	vector<int>ans = findSubarray(arr);

	for(auto x:ans){
		cout<<x<<" ";
	}
	cout<<endl;

	return 0;
}