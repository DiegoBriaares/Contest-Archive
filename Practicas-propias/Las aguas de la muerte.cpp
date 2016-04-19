#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int v[MAX],n,k,d,memo[MAX];
int dp(int i,int s){
	if((v[i]-s)>d||i==n&&(k-s)>d)return (1<<30);
	if(i==n)return 0;
	if(memo[i])return memo[i];
	return memo[i]=min(1+dp(i+1,v[i]),dp(i+1,s));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k>>d;
		for(int i=0;i<n;i++)cin>>v[i];
		cout <<dp(0,0)<<"\n";
	}
