#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	if(n & 1) cout<<"ODD"<<endl;
	else cout<<"EVEN"<<endl;

	return 0;
}