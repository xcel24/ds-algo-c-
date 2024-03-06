#include<bits/stdc++.h>
using namespace std;

void generateSubsets(string output,int n,int open,int close,int i){

	//base case
	if(i==2*n){
		cout<<output<<endl;
	}

	//recursive case

	//placing open brackets
	if(open<n){
		generateSubsets(output+'{',n,open+1,close,i+1);
	}

	//placing closing brackets
	if(close<open){
		generateSubsets(output+'}',n,open,close+1,i+1);
	}

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	string output;

	generateSubsets(output,n,0,0,0);

	return 0;
}