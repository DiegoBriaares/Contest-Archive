#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
ll r;
ll n,p;
ll bit[MAX];
pair<ll,int>v[MAX];
void update(int i){
	while(i<MAX){
		bit[i]++;
		i+=(i&-i);
	}
}
ll query(int i){
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
		for(int i=1;i<=n;i++){
			cin>>v[i].first;
			v[i].second=i;
		}
		cin>>p;
		for(int i=1;i<=n;i++){
			v[i].first+=v[i-1].first-p;
		}
		sort(v,v+n+1);
		for(int i=0;i<=n;i++){
			r+=query(v[i].second+1);
			update(v[i].second+1);
		}
		cout << r<<"\n";
	}
