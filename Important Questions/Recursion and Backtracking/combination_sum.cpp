#include<bits/stdc++.h>
using namespace std;

void combinationSum(vector<int>A, int start, int target, vector<int>temp, vector<vector<int>>&ans){
	//base case
    if(start == A.size()){
        if(target == 0){
            ans.push_back(temp);
        }
        
        return;
    }
    
    //recursive case
    
    //choosing the element
    if(A[start] <= target){
        temp.push_back(A[start]);
        combinationSum(A, start, target - A[start], temp, ans);
        temp.pop_back();
    }
    
    //not choosing the element
    combinationSum(A, start + 1, target, temp, ans);
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	vector<int>A = {2,3,6,7};
	int target = 7;

	vector<int>temp;
	vector<vector<int>>ans;

	combinationSum(A, 0, target, temp, ans);

	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}