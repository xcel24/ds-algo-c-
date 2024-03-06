#include<bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string s;
	getline(cin,s);

	unordered_map<char,int> store;

	//traverse the string and store the values in the map
	for(int i=0;i<s.length();i++){

		if(store.count(s[i])){
			auto it = store.find(s[i]);
			int temp=it->second;
			temp+=1;
			it->second=temp;
		} else{
			store.insert({s[i],1});
		}
	}

	string ans="";

	for(int i=0;i<s.length();i++){
		if(store.count(s[i])){
			auto it=store.find(s[i]);
			ans+=s[i];
			ans+=to_string(it->second);

			//erase this
			store.erase(s[i]);
		}
	}

	cout<<ans<<endl;

	return 0;
}