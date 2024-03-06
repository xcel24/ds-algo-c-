#include<bits/stdc++.h>
using namespace std;

bool canPlaceBirds(vector<int>&nests,int birds,int sep){

	//let's place first bird on 0th index
	int b = 1;
	int last_location = nests[0];

	for(int i=1;i<=nests.size()-1;i++){

		int curr_location = nests[i];
		int diff = curr_location-last_location;

		if(diff >= sep){
			b++;
			last_location = curr_location;

			if(b==birds){
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

	int n,b;
	cin>>n>>b;

	vector<int>nests;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		nests.push_back(x);
	}

	//important step
	sort(nests.begin(),nests.end());

	//angry birds algo
	int s = 0;
	int e = nests[n-1] - nests[0];

	int ans = -1;

	while(s <= e){
		int mid = (s+e)/2;

		bool canPlace = canPlaceBirds(nests,b,mid);

		if(canPlace){
			ans = mid;

			s = mid + 1;
		}else{
			e = mid - 1;
		}
	}

	cout<<ans<<endl;

	return 0;
}