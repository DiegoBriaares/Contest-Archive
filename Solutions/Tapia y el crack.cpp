#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P 9001
#define MOD 1000000007
ll n,m;
set<ll>s;
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
		ll i,j,k,g,h,pot,aux,it;
		bool ok;
		cin>>n>>m;
		for(i=0;i<n;i++){
			cin>>v;
			h=hashing(v);
			s.insert(h);
		}
		for(i=0;i<m;i++){
			cin>>v;
			h=hashing(v);
			ok=false;
			pot=1;
			for(j=v.size()-1;j>=0;j--,pot=(pot*P)){
				h-=pot*(ll)(v[j]);
				for(it='a';it<='c';it++){
					aux=h+(it*pot);
					if(it!=v[j]&&s.find(aux)!=s.end()){
						cout << "SI\n";
						ok=true;
						break;
					}
				}
				if(ok)break;
				h+=pot*(ll)(v[j]);
			}
			if(!ok)cout <<"NO\n";
		}
	}
