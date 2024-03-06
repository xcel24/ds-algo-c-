#include<bits/stdc++.h>
using namespace std;

int findSteps(int n){

	//base case
	if(n<0) return 0;
	if(n==0) return 1;

	//recursive case
	return findSteps(n-1) + findSteps(n-2) + findSteps(n-3);
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	cout<<findSteps(n)<<endl;


	return 0;
}