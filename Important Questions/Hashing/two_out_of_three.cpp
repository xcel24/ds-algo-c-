#include<bits/stdc++.h>
using namespace std;

vector<int> twoOutOfThree(vector<int>A,vector<int>B,vector<int>C){

	unordered_map<int,set<int>>s;

	for(auto x:A){
		s[x].insert(1);
	}

	for(auto y:B){
		s[y].insert(2);
	}

	for(auto z:C){
		s[z].insert(3);
	}

	vector<int> ans;

	for(auto it:s){
		if(it.second.size()>=2){
			ans.push_back(it.first);
		}
	}

	sort(ans.begin(),ans.end());

	return ans;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	vector<int>A = {1,2};
	vector<int>B = {1,3};
	vector<int>C = {2,3};

	vector<int>ans = twoOutOfThree(A,B,C);

	for(auto x:ans){
		cout<<x<<" ";
	}


	return 0;
}