#include <bits/stdc++.h>
using namespace std;
#define MAX 10000012
#define ll long long
ll r;
ll n,k,l;
vector<ll>a,b;
ll memo1[MAX];
ll memo2[MAX];
ll dp1(int i){
	if(i<0||!a.size())return 0;
	if(i>=a.size())return dp1(a.size()-1);
	if(memo1[i]!=-1)return memo1[i];
	return memo1[i]=1LL*a[i]*2LL+dp1(i-k);
}
ll dp2(int i){
	if(i<0||!b.size())return 0;
	if(i>=b.size())return dp2(b.size()-1);
	if(memo2[i]!=-1)return memo2[i];
	return memo2[i]=1LL*b[i]*2LL+dp2(i-k);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		memset(memo1,-1,sizeof(memo1));
		memset(memo2,-1,sizeof(memo2));
		cin>>n>>k>>l;
		for(int i=0;i<n;i++){
			ll x;
			cin>>x;
			if(x==0||x==l)continue;
			if(x>=(l/2)+(l%2)){
				b.push_back(l-x);
			}
			else a.push_back(x);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		r=dp1(a.size()-1)+dp2(b.size()-1);
		for(int i=0;i<=k;i++){
			ll aux=(k-i);
			ll x=a.size()-1-i;
			ll y=b.size()-1-aux;
			r=min(r,dp1(x)+dp2(y)+l);
		}
		cout << r<<"\n";
	}
