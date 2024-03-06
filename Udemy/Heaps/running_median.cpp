#include<bits/stdc++.h>
using namespace std;


int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	priority_queue<int>max_heap;
	priority_queue<int,vector<int>,greater<int>>min_heap;

	int d;
	cin>>d;

	max_heap.push(d);

	float median = d;

	cout<<median<<" ";

	cin>>d;
	while(d != -1){
		//3 cases max_heap>min_heap or min_heap>max_heap or equal

		if(max_heap.size() > min_heap.size()){
			if(d < median){
				min_heap.push(max_heap.top());
				max_heap.pop();

				max_heap.push(d);
			}else{
				min_heap.push(d);
			}

			median = (max_heap.top() + min_heap.top())/2.0;
		}else if(min_heap.size() > max_heap.size()){
			if(d > median){
				max_heap.push(min_heap.top());
				min_heap.pop();

				min_heap.push(d);
			}else{
				max_heap.push(d);
			}

			median = (max_heap.top() + min_heap.top())/2.0;
		}
		else{
			if(d<median){
				max_heap.push(d);
				median = max_heap.top();
			}else{
				min_heap.push(d);
				median = min_heap.top();
			}
		}

		cout<<median<<" ";
		cin>>d;
	}

	return 0;
}