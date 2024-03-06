#include<bits/stdc++.h>
using namespace std;

string fraction(int A,int B){
	string ans="";
    
    int divisor = A / B;
    int remainder = A % B;
    
    ans += to_string(divisor);
    
    if(remainder == 0) return ans;
    
    ans +=".";
    
    unordered_map<int,int>m;

    bool is_repeating = false;
    
    while(remainder != 0 and !is_repeating){
    	if(m.find(remainder) != m.end()){
    		is_repeating = true;
    		break;
    	}

    	m[remainder] = 1;
        remainder = remainder*10;
        int x = remainder / B;
        remainder = remainder % B;
        
        ans += to_string(x);
    }

    if(is_repeating){
    	ans.insert(2,"(");
    	ans+=")";
    }
    
    return ans;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	int num,den;
	cin>>num>>den;

	cout<<fraction(num,den)<<endl;

	return 0;
}