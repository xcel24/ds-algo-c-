#include<bits/stdc++.h>
using namespace std;


int sparsedSearch(string arr[], int n, string key){

	int s = 0;
	int e = n-1;

	while(s<=e){

		int mid = (s+e)/2;
		int mid_left = mid -1;
		int mid_right = mid +1; 

		if(arr[mid]==""){
			while(1){
				if(mid_left<s and mid_right>e){
					return -1;
				}

				else if(arr[mid_right] != ""){
					mid = mid_right;
					break;
				}
				else if(arr[mid_left] != ""){
					mid = mid_left;
					break;
				}

				mid_left--;
				mid_right++;
			}
		}

		if(arr[mid]==key){
			return mid;
		}

		else if(arr[mid]<key){
			s = mid +1;
		}
		else {
			e = mid -1;
		}
	}

	return -1;

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	string arr[] = {"ai","","","bat","","","car","cat","","","dog","e"};
	int n =12;

	string key="dog";

	cout<<sparsedSearch(arr,n,key) +1 <<endl;

	return 0;
}