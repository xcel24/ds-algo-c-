#include<bits/stdc++.h>
using namespace std;

void tripletsUsing2Pointer(vector<int>arr,int targetSum){

	int n=arr.size();

	//step 1
	sort(arr.begin(),arr.end());
	vector<vector<int>>result;

	//step 2 fix 1 and find pair sum for the remaining
	for(int i=0;i<n-2;i++){
		int j=i+1;
		int k=n-1;

		while(j<k){

			int curr_sum=arr[i];
			curr_sum+=arr[j]+arr[k];

			if(curr_sum==targetSum){
				result.push_back({arr[i],arr[j],arr[k]});
				j++;
				k--;
			}

			//if curr sum is greater than decrease k--
			else if(curr_sum>targetSum){
				k--;
			}
			else{
				j++;
			}

		}
	}
	for(auto v:result){
		for(auto no:v){
			cout<<no<<",";
		}
		cout<<endl;
	}
	cout<<"###################"<<endl;
}

void tripletsUsingHashmap(vector<int>arr,int targetSum){
	int n=arr.size();
	vector<vector<int>>result;

	sort(arr.begin(),arr.end());

	for(int i=0;i<n-1;i++){
		unordered_set<int> store;
		for(int j=i+1;j<n;j++){
			int key=targetSum-(arr[i]+arr[j]);
			if(store.find(key) !=store.end() && arr[j]!=key){
				result.push_back({arr[i],arr[j],key});
				continue;
			}
			store.insert(arr[j]);
		}
	}

	for(int i=0;i<result.size();i++){
		sort(result[i].begin(),result[i].end());
	}

	for(auto v:result){
		for(auto no:v){
			cout<<no<<",";
		}
		cout<<endl;
	}

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	int targetSum;
	cin>>targetSum;

	vector<int>arr;

	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		arr.push_back(tmp);
	}

	tripletsUsing2Pointer(arr,targetSum);
	tripletsUsingHashmap(arr,targetSum);

	return 0;
}