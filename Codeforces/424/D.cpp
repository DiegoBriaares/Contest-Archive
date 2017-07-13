#include <bits/stdc++.h>
using namespace std;
#define MAX 2002
#define ll long long
ll n,k,p;
ll v[MAX];
ll keys[MAX];
ll memo[MAX][MAX];
ll dp(int i,int j,ll pos){
	if(i==n)return pos;
	if(j==k)return (1<<30);
	if(memo[i][j])return memo[i][j];
	int aux=(abs(keys[j]-v[i])+abs(keys[j]-p));
	if(k-j>n-i){
		return memo[i][j]=min(dp(i+1,j+1,(pos>aux?pos:aux)),dp(i,j+1,pos));
	}
	else return memo[i][j]=dp(i+1,j+1,(pos>aux?pos:aux));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k>>p;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<k;i++){
			cin>>keys[i];
		}
		sort(v,v+n);
		sort(keys,keys+k);
		cout << dp(0,0,0)<<"\n";
	}
