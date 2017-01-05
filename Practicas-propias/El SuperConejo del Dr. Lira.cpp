#include <bits/stdc++.h>
using namespace std;
#define MAX 1102
int n,c;
bool ok;
int m[MAX][MAX];
int memo[MAX][MAX];
int dx[3]={2,-1,1};
int dy[3]={-1,2,1};
int dp(int i,int j){
	if(i>=n||i<0||j>=c||j<0||m[i][j]==-2)return -(1<<30);
	if(i==n-1&&j==c-1){
		ok=true;
		return m[n-1][c-1];
	}
	if(memo[i][j])return memo[i][j];
	memo[i][j]=-(1<<30);
	for(int idx=0;idx<3;idx++){
		int aux=dp(i+dx[idx],j+dy[idx]);
		memo[i][j]=max(memo[i][j],(aux+m[i][j]<0?0:aux+m[i][j]));
	}
	return memo[i][j];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				cin>>m[i][j];
				if(m[i][j]==-2)m[i][j]=-1;
				else if(m[i][j]==-1)m[i][j]=-2;
			}
		}	
		int aux=dp(0,0);
		if(!ok)cout << "-1\n";
		else cout << aux<<"\n";
	}
