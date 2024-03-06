#include<bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int>A, int B){

	int n = A.size();
	unordered_map<int,int>m;

	vector<int>prefix_xor(n,0);
	prefix_xor[0] = A[0];

	for(int i=1;i<n;i++){
		prefix_xor[i] = prefix_xor[i-1] ^ A[i];
	}

	int ans = 0;

	for(auto x:prefix_xor){
		int xor_needed = x^B;

		if(m.find(xor_needed) != m.end()){
			ans += m[xor_needed];
		}

		if(x == B){
			ans++;
		}

		m[x]++;
	}

	return ans;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	vector<int>A = {5, 6, 7, 8, 9};
	int B = 5;

	cout<<countSubarrays(A,B)<<endl;


	return 0;
}