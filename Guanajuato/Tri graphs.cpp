#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
const long long INF =100000000000000000;
long long dp[MAX][3],m[MAX][3];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t=1;
		while(1){
		long long i,j,k,g,h,n;
		cin>>n;
		if(n==0)return 0;
		for(i=0;i<n;i++){
			for(j=0;j<3;j++){
				cin>>m[i][j];
				dp[i][j]=INF;
			}
		}
		dp[0][0]=INF;
		dp[0][2]=m[0][1]+m[0][2];
		dp[0][1]=m[0][1];
		for(i=1;i<n;i++){
			for(j=0;j<3;j++){
				if(j==0){
					dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+m[i][j];
				}
				if(j==1){
					dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),min(dp[i-1][j+1],dp[i][j-1]))+m[i][j];
				}
				if(j==2){
					dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+m[i][j];
				}
			}
		}
		cout << t<<". "<<dp[n-1][1]<<"\n";
		t++;
		}
	}
