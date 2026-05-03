#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P 9001
#define MOD 1000000007
ll r;
ll n,m,l;
string v;
map<pair<ll,ll>,int>memo;
ll hashing(string v){
	ll res=0;
	for(int i=0;i<l;i++){
		res*=P;
		res+=(ll)(v[i]);
		res%=MOD;
	} 
	return res;
}
ll hashing2(string v){
	ll res=0;
	for(int i=0;i<l;i++){
		res*=P;
		res+=(ll)(v[i]);
	} 
	return res;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		while(cin>>n>>m>>l){
			memo.clear();
			for(int i=0;i<n;i++){
			cin>>v;
			ll h=hashing(v);
			ll h2=hashing2(v);
			ll pot=1;
			ll pot2=1;
			for(int j=l-1;j>=0;j--,pot=(pot*P)%MOD,pot2=(pot2*P)){
				h-=pot*(ll)(v[j]);
				h2-=pot2*(ll)(v[j]);
				h%=MOD;
				if(h<0)h+=MOD;
				memo[make_pair(h,h2)]++;
				h+=pot*(ll)(v[j]);
				h2+=pot2*(ll)(v[j]);
				h%=MOD;
			}
		}
		for(int i=0;i<m;i++){
			r=0;
			cin>>v;
			ll h=hashing(v);
			ll h2=hashing2(v);
			ll pot=1;
			ll pot2=1;
			for(int j=l-1;j>=0;j--,pot=(pot*P)%MOD,pot2=(pot2*P)){
				h-=pot*(ll)(v[j]);
				h2-=pot2*(ll)(v[j]);
				h%=MOD;
				if(h<0)h+=MOD;
				r+=memo[make_pair(h,h2)];
				h+=pot*(ll)(v[j]);
				h2+=pot2*(ll)(v[j]);
				h%=MOD;
			}
			cout << r<<"\n";
		}
		}
	}
