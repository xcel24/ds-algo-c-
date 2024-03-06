#include<bits/stdc++.h>
using namespace std;


//Good Question
int longestBand(vector<int>arr){

	int n=arr.size();
	unordered_set<int>store;

	int largest=0;

	//step 1 store values in the hash set
	for(int i=0;i<n;i++){
		store.insert(arr[i]);
	}

	for(auto element:arr){
		int parent=element-1;

		if(store.find(parent)==store.end()){
			int next_no=element+1;
			int curr=1;

			while(store.find(next_no)!=store.end()){
				curr++;
				next_no+=1;
			}

			largest=max(largest,curr);
		}
	}

	return largest;
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
		int tmp;
		cin>>tmp;

		arr.push_back(tmp);
	}

	cout<<longestBand(arr)<<endl;



	return 0;
}