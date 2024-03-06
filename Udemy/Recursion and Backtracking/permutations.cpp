#include<bits/stdc++.h>
using namespace std;

void permutations(string s,int start){

	//base case
	if(start==s.length()){
		cout<<s<<endl;

		return;
	}


	//recursive case
	for(int i=start;i<s.length();i++){

		swap(s[start],s[i]);

		permutations(s,start+1);

		//backtracking
		swap(s[start],s[i]);
	}

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string s;
	cin>>s;

	permutations(s,0);


	return 0;
}