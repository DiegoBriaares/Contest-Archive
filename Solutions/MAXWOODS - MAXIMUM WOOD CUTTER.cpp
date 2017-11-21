#include <bits/stdc++.h>
using namespace std;
#define MAX 202
int n,c;
char m[MAX][MAX];
int memo[MAX][MAX][2];
int dp(int x,int y,int di){
	if(x<0||y<0||x>=n||y>=c)return 0;
	if(m[x][y]=='#')return 0;
	if(memo[x][y][di])return memo[x][y][di];
	return memo[x][y][di]=(m[x][y]=='T'?1:0)+max(dp(x+1,y,(di+1)%2),dp(x,y+(di==0?1:-1),di));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			memset(memo,0,sizeof(memo));
			cin>>n>>c;
			for(int i=0;i<n;i++){
				for(int j=0;j<c;j++)cin>>m[i][j];
			}
			cout << dp(0,0,0)<<"\n";
		}
	}
