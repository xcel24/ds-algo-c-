#include<bits/stdc++.h>
using namespace std;

bool checkRedundant(string input){

	stack<char>s;

	for(char ch:input){
		if(ch != ')'){
			s.push(ch);
		}
		else{
			//it is )
			bool operator_found = false;
			while(!s.empty() and s.top() != '('){
				char top = s.top();
				if(top=='+' or top=='-' or top=='*' or top=='/'){
					operator_found = true;
				}
				s.pop();
			}
			s.pop();

			if(operator_found==false){
				return true;
			}
		}
	}

	return false;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string input;
	cin>>input;

	if(checkRedundant(input)){
		cout<<"Redundant Paranthesis found"<<endl;
	}else{
		cout<<"No Redundant Paranthesis found"<<endl;
	}


	return 0;
}