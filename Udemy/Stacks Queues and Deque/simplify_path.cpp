#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string path){

	istringstream iss(path);
	vector<string>tokens;

	string token;
	while(getline(iss,token,'/')){
		if(token=="." or token==""){
			continue;
		}
		tokens.push_back(token);
	}

	vector<string>stack;
	if(path[0]=='/'){
		stack.push_back("");
	}

	for(string token: tokens){

		if(token==".."){
			if(stack.size()==0 or stack[stack.size()-1] == ".."){
				stack.push_back("..");
			}
			else if(stack[stack.size()-1]!=""){
				stack.pop_back();
			}
		}else{
			stack.push_back(token);
		}
	}

	if(stack.size()==1 and stack[0]==""){
		return "/";
	}

	ostringstream oss;

	int i=0;
	for(auto x:stack){
		if(i!=0){
			oss<<"/";
		}
		oss<<x;
		i++;
	}

	return oss.str();

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