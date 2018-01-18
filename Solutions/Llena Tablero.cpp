#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
#define INF 999999999
int n,c;
char m[MAX][MAX];
int memo[MAX][10][(1<<9)+2];
int dp(int i,int j,int mask,int past){
	if(i==n)return 0;
	if(memo[i][j][mask]!=-1)return memo[i][j][mask];
	int ans=INF;
	int sigfila=i+(j==c-1?1:0);
	int sigcol=(j==c-1?0:j+1);
	if(m[i][j]=='.'){
		if((mask&(1<<j))){ //Hay uno vertical arriba.
			//Continuar vertical.
			ans=dp(sigfila,sigcol,mask,0);
			//Poner horizontal.
			ans=min(ans,dp(sigfila,sigcol,(mask^(1<<j)),(!sigcol?0:1))+(!past));
		}
		else {
			//Poner vertical.
			ans=min(ans,dp(sigfila,sigcol,(mask|(1<<j)),0)+1);
			//Poner horizontal.
			ans=min(ans,dp(sigfila,sigcol,mask,(!sigcol?0:1))+(!past));
		}
	}
	else {
		if((mask&(1<<j))){
			ans=dp(sigfila,sigcol,(mask^(1<<j)),0);
		}
		else {
			ans=dp(sigfila,sigcol,mask,0);
		}
	}
	return memo[i][j][mask]=ans;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				cin>>m[i][j];
			}
		}
		memset(memo,-1,sizeof(memo));
		cout << dp(0,0,0,0)<<"\n";
	}
