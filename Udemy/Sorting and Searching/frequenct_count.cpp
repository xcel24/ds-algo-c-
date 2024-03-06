#include<bits/stdc++.h>
using namespace std;

int first_occurence(vector<int>&arr,int key){
	int s = 0;
	int e = arr.size()-1;
	int ans = -1;

	while(s <= e){
		int mid = (s+e)/2;

		if(arr[mid] == key){
			ans = mid;

			e = mid-1;
		}
		else if(arr[mid] > key){
			e = mid-1;
		}else {
			s = mid + 1;
		}
	}

	return ans;
}

int last_occurence(vector<int>&arr,int key){
	int s = 0;
	int e = arr.size()-1;
	int ans = -1;

	while(s <= e){
		int mid = (s+e)/2;

		if(arr[mid] == key) {
			ans = mid;

			s = mid + 1;
		} else if(arr[mid] > key) {
			e = mid - 1;
		}else {
			s = mid +1;
		}
	}

	return ans;
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

	cout<<last_occurence(arr,k) - first_occurence(arr,k) + 1<<endl;


	return 0;
}