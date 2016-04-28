#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 10002
#define MAXN 500002
#define P 9001
#define MOD 1000000007
ll hashes[MAXN];
ll pots[MAX];
pair<ll,ll> op[MAX];
int n;
void pw(){
	ll pot=1;
	pots[0]=1;
	for(int i=1;i<=n;i++){
			pot*=P;
			pot%=MOD;
			pots[i]=pot;
		}
}
ll specialhash(string v){
	ll r=0;
	for(int i=0;i<v.size();i++){
		r*=P;
		r+=(ll)(v[i]);
		r%=MOD;
		hashes[i]=r;
	}
	return r;
}
ll hashing(string v){
	ll r=0;
	for(int i=0;i<v.size();i++){
		r*=P;
		r+=(ll)(v[i]);
		r%=MOD;
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;	
		pw();
		string uso;
		int i;
		for(i=0;i<n;i++){
			cin>>uso;
			op[i].first=hashing(uso);
			op[i].second=uso.size();
		}
		sort(op,op+n);
		ll h=0,h2;
		cin>>uso;
		h2=specialhash(uso);
		bool ok;
		for(i=0;i<uso.size();){
			ok=false;
			for(int j=n-1;j>=0;j--){
				if(op[j].first==hashes[i+(op[j].second-1)]-(i==0?0:hashes[i-1]*(pots[(op[j].second)])%MOD)){
					i+=(op[j].second);
					ok=true;
					break;
				}
			}
			if(!ok)break;
		}
		cout <<i<<"\n";
	}
