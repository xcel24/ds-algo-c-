#include<bits/stdc++.h>
using namespace std;

string decimalToBinary(int n){

	string ans="";

	while(n>0){
		int remainder = n%2;
		n=n/2;

		ans+=to_string(remainder);
	}

	reverse(ans.begin(),ans.end());

	return ans;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	cout<<decimalToBinary(n)<<endl;


	return 0;
}