#include <bits/stdc++.h>
using namespace std;
#define MAX 52
#define ll long long
#define INF 100000002
int n,c;
ll S[MAX][MAX];
ll m[MAX][MAX];
ll memo[MAX][MAX][MAX][MAX];
ll dp(int fi,int fj,int ci,int cj){
	if((fi==fj&&ci==cj))return 0;
	if(memo[fi][fj][ci][cj])return memo[fi][fj][ci][cj];
	ll sum=S[fi-1][ci-1]+S[fj][cj]-S[fi-1][cj]-S[fj][ci-1],ans=INF;
	for(int i=fi;i<fj;i++){
		ans=min(ans,dp(fi,i,ci,cj)+dp(i+1,fj,ci,cj));	
	}
	for(int i=ci;i<cj;i++){
		ans=min(ans,dp(fi,fj,ci,i)+dp(fi,fj,i+1,cj));	
	}
	if(ans==INF)return 0;
	return memo[fi][fj][ci][cj]=ans+sum;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=c;j++){
				cin>>m[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=c;j++){
				S[i][j]=m[i][j]+S[i-1][j]+S[i][j-1]-S[i-1][j-1];
			}
		}
		cout << dp(1,n,1,c)<<"\n";
	}
