#include <bits/stdc++.h>
using namespace std;
map<int,long long>memo;
long long dp(long long n){
	if(n==0)return 0;
	if(memo[n])return memo[n];
	long long uso=dp(n/2)+dp(n/3)+dp(n/4);
	if(uso>n)memo[n]=uso;
	else memo[n]=n;
	return memo[n];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		long long n;
		while(cin>>n){
			memo.clear();
			cout << dp(n)<<"\n";
		}
	}
