#include<bits/stdc++.h>
using namespace std;

//Steps
// step 1 Generate all strings
// step 2 Generate the hashes of the above substrings
// step 3 store them in the map, with key as the hash
// step 4 ans = nC2

vector<int> getHash(string &s, int i, int j){

	vector<int>freq(26,0);

	for(int k=i;k<=j;k++){
		freq[s[k]-'a']++;
	}

	return freq;
}

int countAnagrams(string s){

	map<vector<int>,int>m;

	for(int i=0;i<s.length();i++){
		for(int j=i;j<s.length();j++){

			vector<int>freq = getHash(s,i,j);

			m[freq]++;
		}
	}

	int ans = 0;

	for(auto p:m){

		if(p.second >=2){
			int count = p.second;
			ans += ((count) * (count-1)) / 2;
		}
	}

	return ans;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string s;
	cin>>s;

	cout<<countAnagrams(s)<<endl;

	return 0;
}