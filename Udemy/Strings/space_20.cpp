#include<bits/stdc++.h>
using namespace std;

void replace_space(char *str){

	//step 1 calculate spaces
	int space=0;

	for(int i=0;str[i]!='\0';i++){
		if(str[i]==' '){
			space++;
		}
	}

	int idx=strlen(str) + 2*space;

	str[idx]='\0';

	for(int i=strlen(str)-1;i>=0;i--){

		if(str[i]==' '){
			str[idx-1]='0';
			str[idx-2]='2';
			str[idx-3]='%';

			idx=idx-3;
		}
		else{
			str[idx-1]=str[i];
			idx--;
		}
	}
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	char input[1000];
	cin.getline(input,1000);

	replace_space(input);

	cout<<input<<endl;


	return 0;
}