#include<bits/stdc++.h>
using namespace std;

string normalise_string(string s){

	for(int i=0;i<s.length();i++){
		//ignore white spaces
		if((char)s[i]==" "){
			continue;
		}
		if((s[i]-'0')>=65 and (s[i]-'0')<=90){
			s[i]=s[i]+32;
		}
	}
	return s;

}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string input="ABC";
	getline(cin,input);
	

	cout<<normalise_string(input)<<endl;


	return 0;
}