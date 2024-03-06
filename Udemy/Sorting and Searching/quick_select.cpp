#include<bits/stdc++.h>
using namespace std;

int partitiion(vector<int>&arr,int s,int e){

	int pivot = arr[e];
	int i=s-1;

	for(int j=s;j<e;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}

	//swap with arr[e] and not with pivot
	swap(arr[i+1],arr[e]);
 
	return i+1;

}


int kthSmallest(vector<int>&arr,int s,int e,int k){

	//recursive case
	int p = partitiion(arr,s,e);

	if(p==k)return arr[p];

	if(k<p){
		//make call on right array
		return kthSmallest(arr,s,p-1,k);
	}else{
		return kthSmallest(arr,p+1,e,k);
	}

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n,k;
	cin>>n>>k;

	vector<int>arr;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		arr.push_back(x);
	}


	cout<<kthSmallest(arr,0,n-1,k)<<endl;


	return 0;
}