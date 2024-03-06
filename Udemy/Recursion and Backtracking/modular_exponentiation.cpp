#include<bits/stdc++.h>
using namespace std;

long long int moduloExponentiation(int x,int n,long long int M){

	//base case
	if(x==0) return 0;
	if(n==0) return 1;

	//check if n is even or odd
	if(n%2==0){
		long long int y = moduloExponentiation(x,n/2,M);
		y = y*y;
		return y%M;
	}else {
		long long int y = ((x%M)*moduloExponentiation(x,n-1,M))%M;
		return y;
	}

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int x,n;
	cin>>x>>n;

	long long int M = 1000000007;

	cout<<moduloExponentiation(x,n,M);


	return 0;
}