#include <bits/stdc++.h>
using namespace std;
#define MAXK 42
#define MAX 100002
#define ll long long
int n;
ll v[MAX];
ll pref,suf;
struct node {
	bool fin;
	int sons[4];
};
int m=1;
node trie[MAX*MAXK+2];
void add(ll x){
	int pos=1;
	for(int i=MAXK-1;i>=0;i--){
		bool l=(x&(1LL<<i));
		if(!trie[pos].sons[l])trie[pos].sons[l]=++m;
		pos=trie[pos].sons[l];
	}
	trie[pos].fin=true;
}
ll solve(ll x){
	ll r=0;
	int pos=1;
	for(int i=MAXK-1;i>=0;i--){
		bool l=(x&(1LL<<i));
		if(trie[pos].fin)return r;
		if(trie[pos].sons[!l])l=!l;
		if(l)r|=(1LL<<i);
		pos=trie[pos].sons[l];
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
			suf^=v[i];
		}
		ll res=0;
		for(int i=0;i<=n;i++){
			add(pref);
			res=max(res,suf^solve(suf));
			pref^=v[i];
			suf^=v[i];
		}
		cout << res<<"\n";
	}
