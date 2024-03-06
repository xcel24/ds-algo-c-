#include<bits/stdc++.h>
using namespace std;


//do not forget the break statements
void dnf(vector<int>&arr){

	int low = 0;
	int mid = 0;
	int high = arr.size()-1;

	while(mid<=high){
		switch(arr[mid]){
			case 0:
				swap(arr[low],arr[mid]);
				low++;
				mid++;
				break;

			case 1:
				mid++;
				break;

			case 2:
				swap(arr[mid],arr[high]);
				high--;
				break;
		}
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

	dnf(arr);

	for(auto x:arr){
		cout<<x<<",";
	}


	return 0;
}