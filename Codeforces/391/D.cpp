#include <bits/stdc++.h>
using namespace std;
#define MAX 76
#define ll int
#define MOD 1000000007
#define INF 9999999999999
ll n,res;
string v;
ll memo[MAX][(1<<20)+1];
ll dp(int i,ll mask){
	if(memo[i][mask]!=-1)return memo[i][mask];
	memo[i][mask]=(mask&&!(mask&(mask+1))); //Verificar que en realidad esten prendidos los primeros X bits.
	ll m=0;
	for(int j=i+1;j<=n&&m<=20;j++){
		m*=2;
		m+=(v[j-1]-'0');
		if(1<=m&&m<=20)memo[i][mask]+=dp(j,(mask|(1<<(m-1))));
		memo[i][mask]%=MOD;
	}
	return memo[i][mask];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		cin>>v;
		memset(memo,-1,sizeof(memo));
		for(int i=0;i<n;i++){
			res+=dp(i,0);
			res%=MOD;
		}
		cout << res<<"\n";
	}
