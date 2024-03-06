#include<bits/stdc++.h>
using namespace std;

int rotatedSearch(vector<int>&arr,int key){
	int s = 0;
	int e = arr.size()-1;

	while(s <= e) {
		int mid = (s+e)/2;

		if(arr[mid]==key){
			return mid;
		}

		//we have 2 cases either the mid lies on left line or on right line

		//left line
		if(arr[s] <= arr[mid]){

			//again we have 2 cases, whether the key lies on left of left part or on right part
			if(arr[s]<=key and key<=arr[mid]){
				e = mid - 1;
			}else {
				s = mid + 1;
			}
		}
		else {
			if(key >= arr[mid] and key <= arr[e]){
				s = mid +1;
			}else {
				e = mid -1;
			}
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

	cout<<rotatedSearch(arr,k)<<endl;


	return 0;
}