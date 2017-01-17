#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
int n;
ll res;
pair<ll,int>v[MAX];
ll bit[MAX];
void update(int i){
	while(i<MAX){
		bit[i]++;
		i+=(i&-i);
	}
}
ll query(int i){
	if(i==0||i>n)return 0;
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
		freopen("bphoto.in", "r", stdin);
  		freopen("bphoto.out", "w", stdout);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i].first;
			v[i].second=i+1;
		}
		sort(v,v+n);
		reverse(v,v+n);
		for(int i=0;i<n;i++){
			ll a=query(v[i].second-1),b=query(n)-query(v[i].second);
			if(2*min(a,b)<max(a,b)){
				res++;
			}
			update(v[i].second);
		}
		cout << res<<"\n";
	}
