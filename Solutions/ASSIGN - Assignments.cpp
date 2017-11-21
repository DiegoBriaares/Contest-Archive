#include <bits/stdc++.h>
using namespace std;
#define MAX 20
int v[MAX][MAX],n;
long long dp[(1<<20)];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			int k;
			memset(dp,0,sizeof(dp));
			cin>>n;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cin>>v[i][j];
				}
			}
			dp[0]=1;
			int uso=(1<<n)-1;
			for(int i=0;i<uso;i++){
				k=__builtin_popcount(i);
				for(int j=0;j<n;j++){
					if(v[k][j]==1&&(i&(1<<j))==0){
						dp[i|(1<<j)]+=dp[i];
					}
				}
			}
			cout << dp[uso]<<"\n";	
		}
	}
