#include <bits/stdc++.h>
using namespace std;
#define MAX 2002
int n,r;
int v[MAX];
int dp[MAX];
int dp2[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			cin>>n;
			r=0;
			for(int i=0;i<n;i++){
				cin>>v[i];
			}
			for(int i=n-1;i>=0;i--){
				dp[i]=1;
				for(int j=i+1;j<n;j++){
					if(v[j]>v[i]){
						dp[i]=max(dp[i],dp[j]+1);
					}
				}
			}
			for(int i=n-1;i>=0;i--){
			  dp2[i]=1;
				for(int j=i+1;j<n;j++){
					if(v[j]<v[i]){
						dp2[i]=max(dp2[i],dp2[j]+1);
					}
				}
			}
			for(int i=0;i<n;i++){
				r=max(r,dp[i]+dp2[i]-1);
			}
			cout << r<<"\n";
		}
	}
