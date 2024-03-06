#include<bits/stdc++.h>
using namespace std;

void merge(vector<string>&arr,int s, int e){

	int i = s;
	int mid = (s+e)/2;
	int j = mid+1;

	vector<string>tmp;

	while(i<=mid and j<=e){

		//we will make 2 strings and concatenate them compare them and then push to vector
		string s1 = arr[i]+arr[j];
		string s2 = arr[j]+arr[i];

		if(s1<s2){
			tmp.push_back(arr[i]);
			i++;
		}else{
			tmp.push_back(arr[j]);
			j++;
		}
	}

	while(i<=mid){
		tmp.push_back(arr[i]);
		i++;
	}

	while(j<=e){
		tmp.push_back(arr[j]);
		j++;
	}

	int k=0;
	for(int idx=s;idx<=e;idx++){
		arr[idx] = tmp[k++];
	}

	return;

}


void smallestString(vector<string>&arr,int s, int e){

	//base case
	if(s>=e) return;

	//recursive case
	int m = (s+e)/2;

	smallestString(arr,s,m-1);
	smallestString(arr,m+1,e);

	merge(arr,s,e);

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	vector<string>arr;

	for(int i=0;i<n;i++){
		string x;
		cin>>x;

		arr.push_back(x);
	}

	smallestString(arr,0,n-1);

	string ans="";
	for(auto s:arr){
		ans += s;
	}

	cout<<ans<<endl;


	return 0;
}