#include<bits/stdc++.h>
using namespace std;


//This solution takes O(NlogN)
bool bianry_search(vector<int>arr,int left,int right,int key){
	//calculate mid
	int mid = left + (right-left)/2;

	if(right>=left){
		//base case
		if(arr[mid]==key) return true;

		//recursive case
		if(arr[mid]<key){
			//check only in right half
			return bianry_search(arr,mid+1,right,key);
		}

		return bianry_search(arr,left,mid-1,key);
	}

	return false;

}


//This solution will take O(N) time
void findUsingHashSet(vector<int>arr,int target){

	//step 1 create an unordered set
	unordered_set<int> store;

	//step 2 iterate over array and see if that element is present or not
	vector<int> result;

	for(int i=0;i<arr.size();i++){
		//see if the target-arr[i] is present in the set or not
		if(store.find(target-arr[i]) != store.end()){
			result.push_back(arr[i]);
			result.push_back(target-arr[i]);

			cout<<result[0]<<","<<result[1];
			return;
		}

		//then insert arr[i] in set
		store.insert(arr[i]);
	}
	if(result.size()==0) cout<<"No pair found"<<endl;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif
	int n,target;
	cin>>n;
	cin>>target;
	vector<int>arr;
	int temp;

	vector<int>result;

	//building the vector
	for(int i=0;i<n;i++){
		cin>>temp;
		arr.push_back(temp);
	}

	//step 1 sort the vector
	sort(arr.begin(),arr.end());

	//step 2 take 1st element and find the Target - 1st element
	for(int i=0;i<arr.size();i++){
		if(bianry_search(arr,0,arr.size()-1,target-arr[i])){
			result.push_back(arr[i]);
			result.push_back(target-arr[i]);
		}
	}

	// //if no pair found then
	if(result.size()==0){
		result.push_back(-1);
		cout<<result[0]<<endl;
	}else{
		cout<<result[0]<<","<<result[1]<<endl;
	}

	findUsingHashSet(arr,target);



	return 0;
}