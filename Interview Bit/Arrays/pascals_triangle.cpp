#include<bits/stdc++.h>
using namespace std;

void buildPascalsTriangle(int k){
	vector<vector<int>>ans;

	ans.push_back({1});
	ans.push_back({1,1});

	for(int i=2;i<=k;i++){
		vector<int>temp;

		temp.push_back(1);

		vector<int> prevLevel = ans[i-1];

		//here write the logic
		for(int j=0;j<ans[i-1].size() -1 ;j++){
			
			temp.push_back(prevLevel[j] + prevLevel[j+1]);
		}

		temp.push_back(1);

		ans.push_back(temp);
	}

	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int k;
	cin>>k;

	buildPascalsTriangle(k);


	return 0;
}