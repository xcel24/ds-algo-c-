#include<bits/stdc++.h>
using namespace std;

void clearBitsInRange(int &n,int i,int j){
	int a = (~0)<<(j+1);
	int b = (1<<i) - 1;

	int mask = a | b;

	n = n & mask;
}

void replaceBits(int &n, int i, int j, int m){
	clearBitsInRange(n,i,j);

	int mask = m<<i;

	n = n | mask;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n,m,i,j;
	cin>>n>>m>>i>>j;

	replaceBits(n,i,j,m);

	cout<<n<<endl;


	return 0;
}