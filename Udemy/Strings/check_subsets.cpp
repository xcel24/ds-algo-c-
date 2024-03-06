#include<bits/stdc++.h>
using namespace std;

bool isSubset(string s1,string s2){
	int i=s1.length()-1;
	int j=s2.length()-1;

	while(i>=0 and j>=0){
		//case when character matches
		if(s1[i]==s2[j]){
			i--;
			j--;
		}

		//case when it doesn't matches
		else{
			i--;
		}
	}

	if(j==-1)return true;
	return false;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);

	cout<<s1<<endl;
	cout<<s2<<endl;

	if(isSubset(s1,s2)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}


	return 0;
}