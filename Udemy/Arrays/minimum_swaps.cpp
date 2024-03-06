#include<bits/stdc++.h>
using namespace std;

//Good Question
int minimumSwaps(vector<int>arr){

	int n=arr.size();

	//step 1 we will first store the element with their original indices
	pair<int,int>store[n];
	for(int i=0;i<n;i++){
		store[i].first=arr[i];
		store[i].second=i;
	}

	//step 2 sort the pair based on tthe values
	sort(store,store+n);

	vector<bool>visited(n,false);
	int ans=0;

	for(int i=0;i<n;i++){
		int original_pos = store[i].second;

		if(visited[i]==true or original_pos==i){
			continue;
		}

		int cycle=0;
		
		int pos=i;

		while(!visited[pos]){
			visited[pos]=true;
			cycle+=1;

			pos=store[pos].second;
		}

		ans+=(cycle-1);
	}

	return ans;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	vector<int> arr;

	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;

		arr.push_back(tmp);
	}

	cout<<minimumSwaps(arr)<<endl;



	return 0;
}