#include<bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	unordered_map<int,int>store;
	store.insert(make_pair(1,0));
	store.insert(make_pair(2,1));
	store.insert(make_pair(3,2));
	store.insert(make_pair(4,3));
	store.insert(make_pair(5,4));

	if(store.find(2)!=store.end()){
		cout<<store.find(2)->first<<","<<store.find(2)->second<<endl;
	}





	return 0;
}