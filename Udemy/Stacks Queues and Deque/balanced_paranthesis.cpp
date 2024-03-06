#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string input){

	stack<char> s;

	for(auto ch: input){

		switch(ch){
			case '(': s.push(ch);
			case '{': s.push(ch);
			case '[':s.push(ch);
			case ')':
				if(!s.empty() and s.top()=='('){
					s.pop();
				}else{
					return false;
				}
			case '}':
				if(!s.empty() and s.top()=='{'){
					s.pop();
				}else{
					return false;
				}
			case ']':
				if(!s.empty() and s.top()=='['){
					s.pop();
				}else{
					return false;
				}
			default:continue;
		}
	}

	return s.empty();

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string input;
	cin>>input;

	isBalanced(input) ? cout<<"Balanced" : cout<<"Not balanced"<<endl;



	return 0;
}