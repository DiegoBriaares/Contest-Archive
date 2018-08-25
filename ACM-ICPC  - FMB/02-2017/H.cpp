#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll>memo,memo2;
ll n;
ll a(ll x);
ll b(ll x);

ll a(ll x){
    if(x==1)return 1;
    if(memo[x])return memo[x];
   if(x%2==0) return memo[x]=2*a((x/2))-1;
   else  return memo[x]=2*b((x/2)+1)-1;
}

ll b(ll x){
    if(x==1)return 1;
    if(memo2[x])return memo2[x];
   if(x%2==0) return memo2[x]=2*b((x/2));
   else  return memo2[x]=2*a((x/2));
}

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        while(cin>>n){
        if(n==0)return 0;
        memo.clear();
        memo2.clear();
            cout << a(n)<<"\n";
        }
    }
