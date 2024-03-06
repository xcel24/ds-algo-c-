#include<bits/stdc++.h>
using namespace std;

void subsequence(string input,vector<string>&ans,string output){

	//base case
	if(input.length()==0){
		ans.push_back(output);
		return;
	}

	//recursive case
	char ch = input[0];
	string new_input = input.substr(1);

	//includes the character
	subsequence(new_input,ans,output+ch);

	//excludes the character
	subsequence(new_input,ans,output);

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string s;
	getline(cin,s);

	string output="";
	vector<string>ans;

	subsequence(s,ans,output);


	// sort(ans.begin(),ans.end(),compare);

	for(auto a:ans){
		cout<<a<<endl;
	}



	return 0;
}