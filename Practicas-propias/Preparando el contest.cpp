#include <bits/stdc++.h>
using namespace std;
#define MAX 15
#define ll long long
int n;
ll l,r,x;
ll v[MAX];
ll memo[1<<MAX];
int dp(int i,int mask,ll f,ll h,ll s){
	if(i==n&&f!=-1&&h!=-1&&(h-f>=x)&&(l<=s&&s<=r))return 1;
	else if(i==n||s>r)return 0;
	if(memo[mask])return memo[mask];
	memo[mask]=dp(i+1,mask,f,h,s);
	if(!(mask&(1<<i)))memo[mask]+=dp(i+1,(mask|(1<<i)),(f==-1?v[i]:min(f,v[i])),(h==-1?v[i]:max(h,v[i])),s+v[i]);
	return memo[mask];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			memset(memo,0,sizeof(memo));
			cin>>n>>l>>r>>x;
			for(int i=0;i<n;i++){
				cin>>v[i];
			}
			cout << dp(0,0,-1,-1,0)<<"\n";
		}
	}
