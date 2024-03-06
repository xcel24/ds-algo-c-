#include<bits/stdc++.h>
using namespace std;

void maxSubArrayK(vector<int>arr,int k){

	deque<int>Q;

	int i = 0;
	//step 1 is to process first k elements;

	while(i<k){

		while(!Q.empty() and arr[Q.front()] < arr[i]){
			Q.pop_back();
		}

		Q.push_back(i);
		i++;
	}

	while(!Q.empty()){
		cout<<arr[Q.front()]<<" ";
		Q.pop_front();
	}

	cout<<endl;


	//step 2 process the remaining elements
	while(i<arr.size()){

		cout<<arr[Q.front()]<<" ";

		//pop out all those elements which are out of the scope of the window
		while(!Q.empty() and Q.front() <= i-k){
			Q.pop_back();
		}

		while(!Q.empty() and arr[Q.front()] < arr[i]){
			Q.pop_back();
		}

		Q.push_back(i);

		i++;
	}

	while(!Q.empty()){
		cout<<arr[Q.front()]<<" ";
		Q.pop_back();
	}

	return;

}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	vector<int>arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int k = 2;

	maxSubArrayK(arr,k);

	return 0;
}