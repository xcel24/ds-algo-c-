#include<bits/stdc++.h>
using namespace std;

int trappedWater(vector<int>buildings){

	int n=buildings.size();

	//step 1 build left and right array
	vector<int>left(n,0);
	vector<int>right(n,0);

	if(n<=2)return 0;

	left[0]=buildings[0];
	right[n-1]=buildings[n-1];

	for(int i=1;i<n;i++){
		left[i]=max(left[i-1],buildings[i]);
		right[n-i-1]=max(right[n-i],buildings[n-i-1]);
	}

	int result=0;

	for(int i=0;i<n;i++){
		result+=min(left[i],right[i])-buildings[i];
	}

	return result; 



}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	vector<int>buildings;

	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;

		buildings.push_back(tmp);
	}

	cout<<trappedWater(buildings)<<endl;



	return 0;
}