#include<bits/stdc++.h>
using namespace std;

vector<int>maxInWindow(int k,vector<int>v){

	vector<int>ans;

	//step 1, iterate over k size and find max
	int maxima=INT_MIN;
	for(int i=0;i<k;i++){
		maxima = max(maxima,v[i]);
	}

	ans.push_back(maxima);

	for(int i=k+1;i<n;i++){
		
	}

}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int k,n;
	cin>>k>>n;

	vector<int>v;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		v.push_back(x);
	}

	vector<int> ans = maxInWindow(v,k);

	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}



	return 0;
}