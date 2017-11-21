#include <bits/stdc++.h>
using namespace std;
#define MAX 5002
string v;
long long memo[MAX];
long long dp(int i){
	if(i==v.size())return 1;
	if(v[i]=='0')return 0;
	if(memo[i])return memo[i];
	memo[i]=dp(i+1);
	if(i<v.size()-1){
		if(v[i]=='1')memo[i]+=dp(i+2);
		else if(v[i]=='2'&&v[i+1]<='6')memo[i]+=dp(i+2);
	}
	return memo[i];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		while(cin>>v){
			memset(memo,0,sizeof(memo));
			if(v[0]=='0')return 0;
			cout << dp(0)<<"\n";
		}
	}
