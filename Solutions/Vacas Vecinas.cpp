#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int n,k;
int dp[MAX][22];
vector<int>sons[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			sons[a-1].push_back(b-1);
			sons[b-1].push_back(a-1);
		}
		for(int i=0;i<n;i++){ 
			int j;
			cin>>j;
			dp[i][0]=j;
			dp[i][1]+=j;
			for(int l=0;l<sons[i].size();l++){
				dp[sons[i][l]][1]+=j;
			}
		}
		for(int i=2;i<=k;i++){ 
			for(int j=0;j<n;j++){  
				for(int l=0;l<sons[j].size();l++){
					dp[j][i]+=dp[sons[j][l]][i-1];
				}
				dp[j][i]-=(dp[j][i-2]*(sons[j].size()-1>=0?sons[j].size()-1:0));
			}
		}
		for(int i=0;i<n;i++){
			cout << dp[i][k]<<"\n";
		}
	}
