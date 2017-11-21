#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P 967
int n,m;
ll h,pot;
set<ll>S;
bool ok=false;
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
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>v;
			S.insert(hashing(v));
		}
		for(int i=0;i<m;i++){
			cin>>v;
			h=hashing(v);
			pot=1;
			ok=false;
			for(int j=v.size()-1;j>=0;j--,pot*=P){
				h-=(pot*(ll)(v[j]));
				for(int k='a';k<='c';k++){
					ll uso=h+pot*k;
					if(k!=v[j]&&S.find(uso)!=S.end()){
						ok=true;
						cout << "SI\n";
						break;
					}
				}
				if(ok)break;
				h+=(pot*(ll)(v[j]));
			}
			if(!ok)cout <<"NO\n";
		}
	}
