#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string path){

	//step 1 generate tokens
	istringstream iss(path);
	vector<string> tokens;

	string token;

	while(getline(iss,token,'/')){
		if(token == "." or token =="") continue;

		tokens.push_back(token);
	}


	//step 2 we will handle .. case
	vector<string>stack;

	if(path[0] =='/') stack.push_back("");

	for(auto s:tokens){
		if(s==".."){

			if(stack.size()==0 or stack[stack.size()-1] == ".."){
				stack.push_back(s);
			}else if(stack[stack.size()-1] != ""){
				stack.pop_back();
			}
		}else{
			stack.push_back(s);
		}
	}

	int i=0;
	string ans = "";

	for(auto s:stack){
		if(i != 0){
			ans += "/";
		}

		ans += s;
		i++;
	}

	return ans;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string path;
	cin>>path;

	cout<<simplifyPath(path)<<endl;

	return 0;
}