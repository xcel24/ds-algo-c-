#include<bits/stdc++.h>
using namespace std;

void findSubsets(string s,string ans,vector<string>&subsets){

	//base case
	if(s.length()==0){
		subsets.push_back(ans);
		return;
	}

	//case 1 take the character
	findSubsets(s.substr(1),ans+s[0],subsets);

	//case 2 skip the character
	findSubsets(s.substr(1),ans,subsets);

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string s;
	cin>>s;

	string ans = "";
	vector<string>subsets;

	findSubsets(s,ans,subsets);

	for(auto x:subsets){
		cout<<x<<endl;
	}

	cout<<subsets.size()<<endl;

	return 0;
}