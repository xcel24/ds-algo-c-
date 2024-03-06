#include<bits/stdc++.h>
using namespace std;

pair<int,int>subarraySortUsingSorting(vector<int>arr){
	vector<int>tmp_arr=arr;

	sort(tmp_arr.begin(),tmp_arr.end());

	int left=0;
	int right=arr.size()-1;
	int n=arr.size();

	while(left<n and tmp_arr[left]==arr[left]){
		left++;
	}

	while(right>0 and tmp_arr[right]==arr[right]){
		right--;
	}

	if(left==n)return {-1,-1};

	return {left,right};

}

bool outOfOrder(vector<int>arr,int i){
	int curr=arr[i];
	int n=arr.size();
	if(i==0)return curr>arr[1];

	if(i==n-1) return curr<arr[i-1];

	return curr<arr[i-1] or curr>arr[i+1];
}

pair<int,int>subarraySort(vector<int>arr){
	int n=arr.size();

	int smallest=INT_MAX;
	int largest=INT_MIN;

	for(int i=0;i<n;i++){
		int curr=arr[i];

		if(outOfOrder(arr,i)){
			smallest=min(smallest,curr);
			largest=max(largest,curr);
		}
	}

	if(smallest==INT_MAX)return {-1,-1};

	int left=0;
	while(smallest>=arr[left]){
		left++;
	}

	int right=n-1;
	while(largest<=arr[right]){
		right--;
	}

	return {left,right};
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

	auto p=subarraySortUsingSorting(arr);
	auto q=subarraySort(arr);

	cout<<p.first<<" and "<<p.second<<endl;
	cout<<q.first<<" and "<<q.second<<endl;


	return 0;
}