#include <bits/stdc++.h>
using namespace std;
#define MAX 202
#define ll long long
ll n,k;
ll v[MAX];
pair<ll,ll> fact[MAX];
ll memo[MAX][MAX][64];
ll dp(ll i,ll j,ll d,ll c){
	if(j==k)return min(d,c);
	if(i==n)return -(1<<30);
	if(memo[i][j][(min(d,c))])return memo[i][j][(min(d,c))];
	if(!fact[i].first&&!fact[i].second&&((n-i)>(k-j)+2))return memo[i][j][(min(d,c))]=dp(i+1,j,d,c);
	return memo[i][j][(min(d,c))]=max(dp(i+1,j+1,d+fact[i].first,c+fact[i].second),dp(i+1,j,d,c));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<n;i++){
			ll aux=v[i],c=0;
			while(aux%2==0)aux/=2,c++;
			fact[i].first=c;
			aux=v[i],c=0;
			while(aux%5==0)aux/=5,c++;
			fact[i].second=c;
		}
		cout << dp(0,0,0,0)<<"\n";
	}
