#include<bits/stdc++.h>
using namespace std;


int highestMountain(vector<int>arr){

	int n=arr.size();
	int largest=0;

	for(int i=1;i<=n-1;){

		//step 1 go to a peak
		if(arr[i]>arr[i-1] and arr[i]>arr[i+1]){
			int j=i;
			int count=1;

			//backward count
			while(j>1 and arr[j]>arr[j-1]){
				j--;
				count++;
			}

			//forward count
			while(i<=n-2 and arr[i]>arr[i+1]){
				count++;
				i++;
			}
			largest=max(largest,count);
		}else{
			i++;
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


	cout<<highestMountain(arr)<<endl;



	return 0;
}