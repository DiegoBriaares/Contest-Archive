#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
#define ll long long
ll n,c;
ll v[MAX];
priority_queue<pair<ll,ll> >cola;
map<ll,int>idx;
map<ll,int>memo;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		for(int i=1;i<=n;++i){
			cin>>v[i];
			memo[v[i]]++;
			if(!idx[v[i]])idx[v[i]]=i;
		}
		for(int i=1;i<=n;++i){
			if(i==idx[v[i]])cola.push(make_pair(memo[v[i]],i*(-1)));
		}
		while(!cola.empty()){
			ll x=v[(cola.top().second)*(-1)];
			while(memo[x]--)cout << x<<" ";
			cola.pop();
		}
	}
