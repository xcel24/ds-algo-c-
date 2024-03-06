#include<bits/stdc++.h>
using namespace std;

bool isPossibleToDistribute(vector<int>&pages,int val,int m){

	int students = 0;
	int curr_val = 0;

	for(int i=0;i<pages.size();i++){
		curr_val += pages[i];

		if(curr_val >= val){
			students++;
			curr_val = 0;

			if(students == m){
				return true;
			}
		}
	}

	return false;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n,m;
	cin>>n>>m;

	vector<int>pages;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		pages.push_back(x);
	}

	//sort the pages array
	sort(pages.begin(),pages.end());


	int s = pages[n-1];
	int e = 0;
	for(auto p:pages){
		e += p;
	}

	int ans = -1;

	//reading books algo
	while (s <= e){
		int mid = (s+e)/2;

		bool isPossible = isPossibleToDistribute(pages,mid,m);

		if (isPossible){
			ans = mid;
			e = mid - 1;
		}else {
			s = mid + 1;
		}
	}

	cout<<ans<<endl;

	return 0;
}