#include<bits/stdc++.h>
using namespace std;

int getIthBit(int n,int i){

	int mask = 1<<i;

	if(n&mask){
		return 1;
	}else{
		return 0;
	}
}

void setIthBit(int &n,int i){

	int mask = 1<<i;

	n = n | mask;
}

void clearIthBit(int &n,int i){
	int mask = ~(1<<i);

	n = n & mask;
}

void updateIthBit(int &n, int i, int v){
	clearIthBit(n,i);

	int mask = v<<i;

	n = n | mask;
}

void clearLastIBits(int &n, int i){
	int mask = -1<<i;

	n = n & mask;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n,i;
	cin>>n>>i;

	cout<<getIthBit(n,i)<<endl;
	// setIthBit(n,i);
	// cout<<n<<endl;

	// clearIthBit(n,i);
	// cout<<n<<endl;

	//updateIthBit(n,i,0);
	clearLastIBits(n,i);
	cout<<n<<endl;



	return 0;
}