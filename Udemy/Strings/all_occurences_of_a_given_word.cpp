#include<bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string name = "My Name is Prateek. Prateek is my name. Hello Prateek, Good morning Prateek";

	string word;
	getline(cin,word);

	cout<<"Word is "<<word<<endl;

	int index=0;

	while(index<name.length()){
		index=name.find(word,index);

		if(index==-1){
			break;
		}
		cout<<index<<endl;

		index=index+1;
	}



	return 0;
}