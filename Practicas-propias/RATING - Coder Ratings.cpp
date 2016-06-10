#include <bits/stdc++.h>
using namespace std;
#define MAX 300002
#define ll long long
#define par pair<ll,ll>
#define f first
#define s second
ll bit[MAX];
par v[MAX];
par res[MAX];
map<par,ll>memo;
map<par,ll>m;
ll n;
void update(ll i){
	while(i<=MAX){
		bit[i]++;
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
		for(int i=0;i<n;i++){
			cin>>v[i].f>>v[i].s;
			res[i].f=v[i].f;
			res[i].s=v[i].s;
		}
		sort(v,v+n);
		for(int i=0;i<n;i++){
			par uso=make_pair(v[i].f,v[i].s);
			ll aux=query(v[i].s);
			if(m[uso])aux-=m[uso];
			memo[uso]=aux;
			update(v[i].s);
			m[uso]++;
		}
		for(int i=0;i<n;i++){
			par uso=make_pair(res[i].f,res[i].s);
			cout << memo[uso]<<"\n";
		}	
	}
