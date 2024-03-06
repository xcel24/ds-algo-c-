#include<bits/stdc++.h>
using namespace std;

string uniqueSubstring(string str){

	int i=0,j=0,window_len=0,max_window_len=INT_MIN,start_idx=0;

	unordered_map<char,int>store;

	while(j<str.length()){

		char ch = str[j];

		//case1 when the char is already there
		if(store.count(ch) and store[ch]>= i){
			i = store[ch] + 1;  //that is start a new window
			window_len = j-i;
		}

		//case 2 when char is not there
		store[ch]=j;
		j++;
		window_len++;

		//compare maxima
		if(window_len>max_window_len){
			max_window_len=window_len;
			start_idx=i;

		}
	}

	return str.substr(start_idx,max_window_len);
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string input;
	getline(cin,input);

	cout<<uniqueSubstring(input)<<endl;


	return 0;
}