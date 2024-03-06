#include<bits/stdc++.h>
using namespace std;

bool sortBySec(const pair<int,int>&a,const pair<int,int>&b){
	return a.second<b.second;
}

int countActivities(vector<pair<int,int>>activities){

	//step 1 sort the array based on second value
	sort(activities.begin(),activities.end(),sortBySec);

	//take first activity as it's end time is the least
	int count=1;

	int i=0;

	for(int j=1;j<activities.size();j++){
		if(activities[j].first >= activities[i].second){
			count++;
			i=j;
		}
	}

	return count;


}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n;
	cin>>n;

	vector<pair<int,int>>activities;

	for(int i=0;i<n;i++){
		int s,e;
		cin>>s>>e;

		activities.push_back(make_pair(s,e));
	}

	cout<<countActivities(activities)<<endl;


	return 0;
}