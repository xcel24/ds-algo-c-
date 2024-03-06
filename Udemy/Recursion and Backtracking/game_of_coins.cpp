#include<bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>coins,int i,int j){

	//base case
	if(i==j) return coins[i];
	if(j==i+1) return max(coins[i],coins[j]);


	//recursive case
	int option1 = coins[i] + min(maxCoins(coins,i+2,j),maxCoins(coins,i+1,j-1));
	int option2 = coins[j] + min(maxCoins(coins,i+1,j-1),maxCoins(coins,i,j-2));

	return max(option1,option2);
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	vector<int>coins;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		coins.push_back(x);
	}

	cout<<maxCoins(coins,0,n-1)<<endl;


	return 0;
}