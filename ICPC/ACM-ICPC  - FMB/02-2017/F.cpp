#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
#define ll long long
string v;
int f,n,r;
ll arr[MAX];
ll memo[MAX][MAX];
ll dp(int i,int p){
	if(i==n)return 0;
	if(memo[i][p])return memo[i][p];
	memo[i][p]=dp(i+1,p);
	if(arr[i]>=p){
		memo[i][p]=max(memo[i][p],1+dp(i+1,(arr[i]+f)%26));
	}
	return memo[i][p];
}
    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t;
        cin>>t;
        while(t--){
        	memset(memo,0,sizeof(memo));
            cin>>v;
            cin>>f;
            n=v.size();
            for(int i=0;i<n;i++)arr[i]=v[i]-'a';
            cout << dp(0,0)<<"\n";
        }
    }
