#include<bits/stdc++.h>
using namespace std;

void generateSubarrays(vector<int>arr,int start,vector<int>temp,vector<int>&ans){

	//base case
	if(start==arr.size()){
		if(temp.size()>0){
			int maxima = *max_element(temp.begin(),temp.end());
			ans.push_back(maxima);
		}
		return ;
	}

	//recursive case

	//case 1 take the number
	temp.push_back(arr[start]);
	generateSubarrays(arr,start+1,temp,ans);
	temp.pop_back();

	//case 2 leave the number
	generateSubarrays(arr,start+1,temp,ans);

	return;

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	vector<int>arr = {1,2,4};
	vector<int>ans;
	vector<int>temp;

	generateSubarrays(arr,0,temp,ans);

	return 0;
}