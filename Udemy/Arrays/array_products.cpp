#include<bits/stdc++.h>
using namespace std;

void productOutput(vector<int>arr){
	//Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    //update the output array and return
    //complete the code
    vector<int>left(n,0);
    vector<int> right(n,0);
    
    //fill left
    left[0]=1;
    right[n-1]=1;
    for(int i=1;i<n;i++){
        left[i]=left[i-1]*arr[i-1];
    }

    for(int i=n-2;i>=0;i--){
        right[i]=right[i+1]*arr[i+1];
    }

    for(int i=0;i<n;i++){
        output[i]=left[i]*right[i];
    }
    
    for(int i=0;i<n;i++){
    	cout<<output[i]<<",";
    }
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif
	int n;
	cin>>n;
	vector<int>arr;
	int temp;

	vector<int>result;

	//building the vector
	for(int i=0;i<n;i++){
		cin>>temp;
		arr.push_back(temp);
	}

	productOutput(arr);


	return 0;
}