#include<bits/stdc++.h>
using namespace std;

string getKey(string temp,int column){

	stringstream ss(temp);

	string token;

	vector<string>tokens;

	while(getline(ss,token,' ')){
		tokens.push_back(token);
	}

	return tokens[column-1];
}

int getNumericValue(string x){
	int ans=0;
	int power=1;

	for(int i=x.length()-1;i>=0;i--){
		ans+=(x[i]-'0')*power;
		power=power*10;
	}

	return ans;
}

bool sortComparatorLexicographically(const pair<string,string>&a, const pair<string,string>&b){
	return a.first<b.first;

}
bool sortComparatorNumerically(const pair<string,string>&a, const pair<string,string>&b){
	int val1=getNumericValue(a.first);
	int val2 = getNumericValue(b.first);

	return val1<val2;
}



vector<string>mySortFunction(vector<pair<string,string>>keyToStringMap,string reversal,string orderBy){
	vector<string>ans;

	if(orderBy!="numeric"){
		sort(keyToStringMap.begin(),keyToStringMap.end(),sortComparatorLexicographically);
	}else{
		sort(keyToStringMap.begin(),keyToStringMap.end(),sortComparatorNumerically);
	}

	if(reversal=="true"){
		for(int i=keyToStringMap.size()-1;i>=0;i--){
			ans.push_back(keyToStringMap[i].second);
		}
	}else{
		for(int i=0;i<keyToStringMap.size();i++){
			ans.push_back(keyToStringMap[i].second);
		}
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

	cin.get(); //this is used to consume extra \n

	vector<string> arr;
	string tmp;

	for(int i=0;i<n;i++){
		getline(cin,tmp);

		arr.push_back(tmp);
	}

	int column;
	string reversal,orderBy;

	cin>>column>>reversal>>orderBy;

	vector<pair<string,string>>keyToStringMap;

	for(int i=0;i<n;i++){
		string key= getKey(arr[i],column);
		keyToStringMap.push_back({key,arr[i]});
	}

	vector<string> ans = mySortFunction(keyToStringMap,reversal,orderBy);

	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}