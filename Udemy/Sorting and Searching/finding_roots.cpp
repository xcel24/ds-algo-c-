#include<bits/stdc++.h>
using namespace std;

float squareRoot(int n, int p) {

	int s = 0;
	int e = n;

	float ans = 0;

	//Binary search for the Integer part

	while (s <= e){
		int mid = (s+e)/2;

		if(mid*mid == n){
			return mid;
		}
		else if(mid*mid < n){
			ans = mid;
			s = mid +1;
		}else {
			e = mid -1;
		}
	}

	//Linear search for precision part
	float inc = 0.1;
	for(int i=1; i<=p; i++){

		while (ans*ans <=n) {
			ans += inc;
		}

		ans = ans - inc;
		inc = inc/10;
	}

	return ans;

}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int n,p;
	cin>>n>>p;

	cout<<squareRoot(n,p)<<endl;


	return 0;
}