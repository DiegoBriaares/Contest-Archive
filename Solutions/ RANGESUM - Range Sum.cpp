#include <bits/stdc++.h>
using namespace std;
#define MAX 200102
#define MAXN 200000
#define ll long long 
ll bit[MAX];
ll n;
int p;
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
		p=(MAXN-n)+1;
		for(int i=p;i<=MAXN;i++){
			ll x;
			cin>>x;
			update(i,x);
		}
		cin>>n;
		for(int i=0;i<n;i++){
			ll a,b,c;
			cin>>a;
			if(a==1){
				cin>>b>>c;
				b=(b+p)-1;
				c=(c+p)-1;
				cout << (query(c)-query(b-1))<<"\n";
			}
			else {
				cin>>b;
				p--;
				update(p,b);
			}
		}
	}
