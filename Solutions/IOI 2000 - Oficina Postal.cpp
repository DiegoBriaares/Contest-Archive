#include <bits/stdc++.h>
using namespace std;
#define MAX 302
#define MAXK 32
#define ll long long
ll n,p;
ll v[MAX];
int ne[MAX][MAX];
int memo[MAX][MAXK];
int DP[MAX][MAX];
void precalc(){
	for(int i=2;i<=n;i++){
		DP[0][i]=(DP[0][i-1]+(i-1)*(v[i]-v[i-1]));
	}
	for(int i=n-1;i>0;i--){
		DP[i][n+1]=(DP[i+1][n+1]+(n-i)*(v[i+1]-v[i]));
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i+1;k<j;k++){
				DP[i][j]+=min(abs(v[k]-v[i]),abs(v[k]-v[j]));
			}
		}
	}
}
int dp(int i,int j){
	if(j==p)return DP[i][n+1];
	if(i>n)return (1<<30);
	if(memo[i][j])return memo[i][j];
	memo[i][j]=(1<<30);
	for(int k=i+1;k<=n;k++){
		int aux=dp(k,j+1)+DP[i][k];
		if(aux<memo[i][j]){
			memo[i][j]=aux;
			ne[i][j]=k;
		}
	}
	return memo[i][j];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>p;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		precalc();
		int r=(1<<30),idx;
		for(int i=1;i<n;i++){
			int aux=dp(i,1)+DP[0][i];
			if(aux<r){
				r=aux;
				idx=i;
			}
		}
		cout << r<<"\n";
		for(int i=idx,j=0;j<p;j++,i=ne[i][j]){
			cout << v[i]<<" ";
		}
		cout << "\n";
	}
