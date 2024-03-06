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


void quick_sort(vector<int>&arr, int s, int e){

	//base case
	if(s>=e)return;

	//recursive case
	int p = partitiion(arr,s,e);
	//quick sort on left part of array
	quick_sort(arr,s,p-1);
	//quick sort on right part of array
	quick_sort(arr,p+1,e);

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	vector<int>arr;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		arr.push_back(x);
	}

	quick_sort(arr,0,arr.size()-1);

	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<",";
	}

	return 0;
}