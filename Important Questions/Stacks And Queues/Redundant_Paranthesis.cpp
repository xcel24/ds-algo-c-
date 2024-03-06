#include<bits/stdc++.h>
using namespace std;

bool hasRedundant(string A){

	stack<char>s;

	for(int i=0;i<A.length();i++){

		if(A[i] != ')' and A[i] !='}' and A[i] != ']'){
			s.push(A[i]);
		}else{

			bool operator_found = false;
			if(A[i]==')'){
				while(!s.empty() and s.top() != '('){

					if(s.top() =='+' or s.top()=='-' or s.top() =='*' or s.top() =='/'){
						operator_found = true;
					}
					s.pop();
				}

				s.pop();

				if(operator_found == false) return true;

			}
			else if(A[i]=='}'){
				while(!s.empty() and s.top() != '{'){

					if(s.top() =='+' or s.top()=='-' or s.top() =='*' or s.top() =='/'){
						operator_found = true;
					}
					s.pop();
				}

				s.pop();

				if(operator_found == false) return true;

			}

			else if(A[i]==']'){
				while(!s.empty() and s.top() != '['){

					if(s.top() =='+' or s.top()=='-' or s.top() =='*' or s.top() =='/'){
						operator_found = true;
					}
					s.pop();
				}

				s.pop();

				if(operator_found == false) return true;

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

	string A;
	cin>>A;

	if(hasRedundant(A)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}

	return 0;
}