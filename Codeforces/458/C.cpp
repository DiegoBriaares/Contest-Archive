#include <bits/stdc++.h>
using namespace std;
#define MAX 1012
#define MAX_LOG 13
#define ll long long
#define MOD 1000000007
ll n,k;
string v;
ll f[MAX];
ll memo[MAX][MAX][2];
ll calc(int x){
	int op=0;
	while(x>1){
		int unos=0;
		for(int i=0;i<MAX_LOG;i++){
			if((x&(1<<i)))unos++;
		}
		x=unos;
		op++;
	}
	return op;
}
void prec(){
	f[0]=0;
	f[1]=1;
	for(int i=2;i<MAX;i++){
		f[i]=calc(i);
	}
}
ll dp(int i,int j,bool p){
	if(i==n){
		return ((f[j]+(j>0?1:0))==k?1:0);
	}
	if(memo[i][j][p]!=-1)return memo[i][j][p];
	if(p)memo[i][j][p]=dp(i+1,j+1,p)+dp(i+1,j,p);
	else {
		if(v[i]=='1')memo[i][j][p]=dp(i+1,j+1,p)+dp(i+1,j,true);
		else memo[i][j][p]=dp(i+1,j,p);
	}
	memo[i][j][p]%=MOD;
	return memo[i][j][p];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>v;
		cin>>k;
		if(!k){
			cout << "1\n";
			return 0;
		}
		n=v.size();
		prec();
		memset(memo,-1,sizeof(memo));
		cout << dp(0,0,0)<<"\n";
	}
