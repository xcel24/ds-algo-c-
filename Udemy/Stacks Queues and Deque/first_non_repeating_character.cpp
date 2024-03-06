#include<bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	char ch;
	cin>>ch;

	queue<char>q;
	int freq[27] = {0};

	while(ch !='.'){

		q.push(ch);
		freq[ch-'a']++;

		while(!q.empty()){
			int idx = q.front()-'a';
			if(freq[idx]>1){
				q.pop();
			}else{
				cout<<q.front()<<endl;
				break;
			}
		}
		if(q.empty()){
			cout<<"-1"<<endl;
		}
		cin>>ch;
	}


	return 0;
}