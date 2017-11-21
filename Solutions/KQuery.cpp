#include <bits/stdc++.h>
using namespace std;
#define MAX 300002
#define ll long long
ll n,q;
pair<ll,ll>v[MAX];
ll bit[MAX];
ll r[MAX];
ll pos;
pair<ll,pair<pair<ll,ll>,ll> >p[MAX];
void update(ll i,ll x){
	while(i<=MAX){
		bit[i]+=x;
		i+=(i&-i);
	}
}
ll query(ll i){
	ll s=0;
	while(i>0){
		s+=bit[i];
		i-=(i&-i);
	}
	return s;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i].first;
			v[i].second=i+1;
		}
		sort(v,v+n);
		reverse(v,v+n);
		cin>>q;
		for(int i=0;i<q;i++){
			cin>>p[i].second.first.first>>p[i].second.first.second>>p[i].first;
			p[i].second.second=i;
		}
		sort(p,p+q);
		reverse(p,p+q);
		for(int i=0;i<q;i++){
			while(v[pos].first>p[i].first&&pos<n){
				update(v[pos++].second,1);
			}
			r[p[i].second.second]=query(p[i].second.first.second)-query(p[i].second.first.first-1);
		}
		for(int i=0;i<q;i++)cout << r[i]<<"\n";
	}
