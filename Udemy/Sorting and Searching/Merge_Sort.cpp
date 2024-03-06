#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int start,int end){

	int i=start;
	int mid=(start+end)/2;
	int j=mid+1;

	vector<int>temp;

	while(i<=mid and j<=end){

		if(arr[i]<=arr[j]){
			temp.push_back(arr[i]);
			i++;
		}
		else{
			temp.push_back(arr[j]);
			j++;
		}
	}

	
	while(j<=end){
		temp.push_back(arr[j]);
		j++;
	}
	

	while(i<=mid){
		temp.push_back(arr[i]);
		i++;
	}

	//copy back the elements
	int k=0;
	for(int i=start;i<=end;i++){
		arr[i]=temp[k++];
	}

	return;

}

void mergeSort(vector<int>&arr,int start,int end){
	
	//base case
	if(start>=end)return;

	//recursive case
	int mid = (start+end)/2;

	mergeSort(arr,start,mid);
	mergeSort(arr,mid+1,end);


	return merge(arr,start,end);
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

	int start=0;
	int end=arr.size()-1;

	mergeSort(arr,start,end);

	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<",";
	}



	return 0;
}