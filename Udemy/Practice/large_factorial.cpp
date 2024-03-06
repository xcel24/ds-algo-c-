#include<bits/stdc++.h>
using namespace std;

int multiply(int res[],int x,int res_size){
	cout<<"hello world"<<endl;

	int carry = 0;
	for(int i=0;i<res_size;i++){
		int prod = res[i]*x + carry;
		cout<<"prod is"<<prod<<endl;

		res[i] = prod%10;
		carry = prod/10;
	}

	int j=res_size;

	while(carry){
		res[j] = carry%10;
		carry = carry/10;
		res_size++;
	}

	return res_size;
}


string largeFactorial(int n){

	int res[100] = {0};
	res[0] = 1;
	int res_size = 1;

	for(int i=2;i<=n;i++){
		res_size = multiply(res,i,res_size);
	}

	string ans="";

	for(int i=res_size-1;i>=0;i--){
		ans += res[i];
	}

	return ans;

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	cout<<largeFactorial(n)<<endl;

	return 0;
}