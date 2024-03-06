#include<bits/stdc++.h>
using namespace std;

int numberOfSetBits(int n){

	int count=0;
	while(n>0){
		if(n & 1){
			count++;
			n = n>>1;
		}else{
			n = n>>1;
		}
	}

	return count;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	cout<<numberOfSetBits(n)<<endl;


	return 0;
}