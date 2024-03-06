#include<bits/stdc++.h>
using namespace std;

void generateCombinations(string input,unordered_map<char,string>map,int i,string output){

	//base case
	if(i== input.length()){
		cout<<output<<endl;
	}

	//recursive case
	string x = map[input[i]];
	for(int j=0;j<x.length();j++){

		generateCombinations(input,map,i+1,output+x[j]);
	}

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string s;
	cin>>s;

	unordered_map<char,string>map;

	map['0'] = ""; 
	map['1'] = "";
	map['2'] = "ABC";
	map['3'] = "DEF";
	map['4'] = "GHI";
	map['5'] = "JKL";
	map['6'] = "MNO";
	map['7'] = "PQRS";
	map['8'] = "TUV";
	map['9'] = "WXYZ";

	string output;

	generateCombinations(s,map,0,output);



	return 0;
}