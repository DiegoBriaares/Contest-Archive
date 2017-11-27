#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll res,s;
ll n,x,k;
vector<ll>v;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>x>>k;
		for(int i=0;i<n;i++){
			ll x;
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++){
			ll aux =(v[i]-(v[i]%x))+(k-(v[i]%x==0))*x;
			ll aux2=aux+x-1;
			aux = max(aux,v[i]);
			int fin=upper_bound(v.begin(),v.end(),aux2)-v.begin();
			int in=lower_bound(v.begin(),v.end(),aux)-v.begin();
			res+=(fin-in);
		}
		cout << res<<"\n";
	}
