#include <bits/stdc++.h>
using namespace std;
#define MAX 300002
#define ll long long
const int MAX1 = 1e6 + 5;
ll bit[MAX];
ll v[MAX];
ll memo[MAX1];
ll r[MAX];
pair<ll,pair<ll,ll> >p[MAX];
ll n;
ll q;
ll idx;
void update(ll i,ll x){
	while(i<=MAX){
		bit[i]+=x;
		i+=(i&-i);
	}
}
ll query(ll i){
	ll r=0;
	while(i>0){
		r+=bit[i];
		i-=(i&-i);
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		cin>>q;
		for(int i=0;i<q;i++){
			cin>>p[i].second.first>>p[i].first;
			p[i].second.second=i;
		}
		sort(p,p+q);
		memset(memo,-1,sizeof(memo));
		for(int i=1;i<=n;i++){
			if(memo[v[i]]!=-1)update(memo[v[i]],-1);
			memo[v[i]]=i;
			update(i,1);
			while(p[idx].first==i&&idx<q){
				r[p[idx].second.second]=query(i)-query(p[idx].second.first-1);
				idx++;
			}
		}
		for(int i=0;i<q;i++)cout <<r[i]<<"\n";
	}
