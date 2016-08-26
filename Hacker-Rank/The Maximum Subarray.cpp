#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n;
ll memo[MAX][2];
ll v[MAX];
ll dp(int i,bool ok){
    if(i==n&&ok)return 0;
    if(i==n)return -(1<<30);
    if(memo[i][ok])return memo[i][ok];
    return memo[i][ok]=max(v[i]+dp(i+1,true),dp(i+1,ok));
}
int main() {
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(memo,0,sizeof(memo));
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ll k=v[n-1],r=v[n-1];
        for(int i=n-2;i>=0;i--){
            k=max(v[i],k+v[i]);
            r=max(r,k);
        }
        cout <<r<<" "<<dp(0,false)<<"\n";
    }
}
