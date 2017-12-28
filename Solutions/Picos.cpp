#include <bits/stdc++.h>
using namespace std;
#define MAX 1000102
#define ll long long
#define MOD 46309
ll n,sum;
pair<ll,ll> v[MAX];
ll mp[MAX];
ll bit[MAX];
void update(int i,ll x){
	while(i<MAX){
		bit[i]+=x;
		i+=(i&-i);
	}
}
ll query(int i){
	ll sum=1;
	while(i>0){
		sum+=bit[i];
		i-=(i&-i);
	}
	return sum%MOD;
}
ll A[MAX],B[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i].first;
			v[i].second=i;
		}
		sort(v+1,v+n+1);
		ll p=-1,m=0;
		for(int i=1;i<=n;i++){
			if(v[i].first!=p){
				m++;
				p=v[i].first;
			}
			mp[v[i].second]=m;
		}
		for(int i=1;i<=n;i++){
			ll aux=query(mp[i]-1);
			update(mp[i],aux);
			A[i]=aux;
		}
		memset(bit,0,sizeof(bit));
		for(int i=n;i>=1;i--){
			B[i]=query(mp[i]-1);
			update(mp[i],B[i]);
		}
		for(int i=1;i<=n;i++){
			sum+=(A[i])*(B[i])%MOD;
			sum%=MOD;
		}
		cout << sum%MOD<<"\n";
	}
