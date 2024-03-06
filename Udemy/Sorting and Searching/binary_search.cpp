#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>&arr,int key){
	int s = 0;
	int e = arr.size()-1;

	while(s <= e){
		int mid = (s+e)/2;

		if(arr[mid] == key){
			return mid;
		}
		else if(arr[mid]>key){
			//search in left half
			e = mid-1;
		}else {
			s = mid +1;
		}
	}

	return -1;
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

	int ans = binarySearch(arr,k);

	if(ans == -1){
		cout<<"Key not found"<<endl;
	}else{
		cout<<ans<<endl;
	}

	return 0;
}