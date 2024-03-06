#include<bits/stdc++.h>
using namespace std;

string firstNonRepeating(string s){

	queue<char>q;
	int freq[27] = {0};

	string ans = "";

	for(auto ch: s){

		q.push(ch);
		freq[ch-'a']++;

		while(!q.empty()){

			int idx = q.front() - 'a';

			if(freq[idx]>1){
				q.pop();
			}else{
				ans += q.front();
				//this line is very important
				break;
			}
		}

		if(q.empty()){
			ans += "#";
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

	cout<<firstNonRepeating(s)<<endl;

	return 0;
}