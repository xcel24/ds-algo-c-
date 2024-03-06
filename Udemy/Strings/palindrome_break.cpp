#include<bits/stdc++.h>
using namespace std;


string palindrome_break(string s){

	//base case
	if(s.length()==1) return "";

	int i=0;

	while(s[i]=='a' and i<(s.length()/2)) i++;

	if(i==(s.length()/2)){
		s[s.length()-1]='b';

	}else{
		s[i]='a';
	}

	return s;

}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string input="abccba";

	cout<<palindrome_break(input)<<endl;

	return 0;
}