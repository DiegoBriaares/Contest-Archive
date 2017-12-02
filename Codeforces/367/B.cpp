#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n,q;
ll dp[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			dp[x]++;
		}
		for(int i=1;i<MAX;i++)dp[i]+=dp[i-1];
		cin>>q;
		while(q--){
			ll x;
			cin>>x;
			cout << dp[min((ll)MAX-1,x)]<<"\n";
		}	
	}
