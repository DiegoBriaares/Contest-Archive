#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P 9001
#define MOD 1000000007
#define par pair<ll,ll>
ll n,m;
set<par>s;
ll hashing2(string v){
	ll r=0;
	for(int i=0;i<v.size();i++){
		r*=P;
		r+=(ll)(v[i]);
		r%=MOD;
	} 
	return r;
}
ll hashing(string v){
	ll r=0;
	for(int i=0;i<v.size();i++){
		r*=P;
		r+=(ll)(v[i]);
	} 
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		string v;
		ll i,j,k,g,h,pot,pot2,aux,aux2,it;
		bool ok;
		cin>>n>>m;
		for(i=0;i<n;i++){
			cin>>v;
			g=hashing(v);
			h=hashing2(v);
			par uso=make_pair(g,h);
			s.insert(uso);
		}
		for(i=0;i<m;i++){
			cin>>v;
			g=hashing(v);
			h=hashing2(v);
			ok=false;
			pot=pot2=1;
			for(j=v.size()-1;j>=0;j--,pot*=P,pot2=(pot2*P)%MOD){
				g-=pot*(ll)(v[j]);
				h-=pot2*(ll)(v[j]);
				h%=MOD;
				if(h<0)h+=MOD;
				for(it='a';it<='c';it++){
					aux2=h+(it*pot2);
					aux2%=MOD;
					aux=g+(pot*it);
					par uso=make_pair(aux,aux2);
					if(it!=v[j]&&s.find(uso)!=s.end()){
						cout << "SI\n";
						ok=true;
						break;
					}
				}
				if(ok)break;
				g+=pot*(ll)(v[j]);
				h+=pot2*(ll)(v[j]);
				h%=MOD;
			}
			if(!ok)cout <<"NO\n";
		}
	}
