#include<bits/stdc++.h>
using namespace std;

string distinct_window(string s){

	//step 1 will build the pattern from the given string with freq count of 1
	unordered_set<char>FP;
	for(int i=0;i<s.length();i++){
		FP.insert(s[i]);
	}

	unordered_map<char,int>m;
	int i=0,j=0;
	int start_idx=-1;
	int min_len = s.length();

	while(i<s.length()){
		m[s[i]]++;

		if(m.size()==FP.size()){
			while(m[s[j]]>1){
				m[s[j]]--;
				j++;
			}

		int win_len=i-j+1;
		if(win_len<min_len){
			min_len=win_len;
			start_idx=j;
		}

		}

		i++;
	}

	return s.substr(start_idx,min_len);

}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string s;
	cin>>s;

	cout<<distinct_window(s)<<endl;


	return 0;
}