#include<bits/stdc++.h>
using namespace std;

int minimumLightsToActivate(vector<int>&A,int B){
	int ans = 0;
	int idx = -1;
	int n = A.size();

	int j = 0;

	while(j<A.size()){

		for(int i=max(0,j-B+1);i<min(n,j+B);i++){
			if(A[i]==1){
				idx = i;
			}
		}

		if(idx==-1) return -1;
		ans++;

		j = idx + B;
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

	vector<int>A;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		A.push_back(x);
	}

	int B;
	cin>>B;

	cout<<minimumLightsToActivate(A,B)<<endl;

	return 0;
}