#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>&arr, int s, int e){

	int i = s;
	int mid = (s+e)/2;
	int j = mid+1;

	vector<int>temp;
	int count=0;

	while(i<=mid and j<=e){

		if(arr[i]<arr[j]){
			temp.push_back(arr[i]);
			i++;
		}
		else{
			temp.push_back(arr[j]);
			count += (mid-i+1);
			j++;
		}
	}

	while(i<=mid){
		temp.push_back(arr[i]);
		i++;
	}

	while(j<=e){
		temp.push_back(arr[j]);
		j++;
	}

	int k=0;
	for(int idx=s;idx<=e;idx++){
		arr[idx] = temp[k++];
	}

	return count;
}



//important thing to note is that pass the array by reference not by value
int inversion_count(vector<int>&arr,int s, int e){

	//base case
	if(s>=e)return 0;

	//recursive case
	int m = (e + s)/2;
	int C1 = inversion_count(arr, s ,m);
	int C2 = inversion_count(arr, m+1, e);
	int CI = merge(arr, s, e);

	return C1+C2+CI;

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

	int e = arr.size()-1;

	cout<<inversion_count(arr,0,e)<<endl;


	return 0;
}