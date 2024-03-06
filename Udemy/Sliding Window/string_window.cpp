#include<bits/stdc++.h>
using namespace std;
// GOOD QUESTION !!!


string find_window(string s, string p){

	//step 1 create frequency map of pattern
	int FP[256]={0};

	for(int i=0;i<p.length();i++){
		FP[p[i]]++;
	}

	//step 2 frequency map of string
	int FS[256]={0};

	int cnt=0;
	int start=0; //for the left contraction.
	int min_window_size = INT_MAX;
	int start_idx=-1; //for the best window

	for(int i=0;i<s.length();i++){

		//expand the window towards right
		char ch=s[i];

		//current char goes inside the window
		FS[ch]++;

		//Maintains how many chars have been matched so far
		if(FP[ch] != 0 and FS[ch] <= FP[ch]){
			cnt += 1;
		}

		//if all chars in pattern are matched
		if(cnt == p.length()){
			//we start contracting from the left

			while(FP[s[start]] == 0 or FS[s[start]] > FP[s[start]]) {
				FS[s[start]]--;
				start++;
			}

			int window_size = i - start + 1;

			if(window_size<min_window_size){
				min_window_size=window_size;
				start_idx=start;

			}

		}

	}

	if(start_idx==-1){
		return "No window found";
	}

	return s.substr(start_idx,min_window_size);
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string s,p;
	cin>>s>>p;

	cout<<find_window(s,p)<<endl;


	return 0;
}