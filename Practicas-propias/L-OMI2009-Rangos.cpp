#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
#define MOD 10000
#define ll long long
#define fst first
#define snd second
ll n,a,p;
ll r;
pair<ll,ll>v[MAX];
ll solve(ll x){
	if(x<=0)return 0;
	return (x*(x+1))/2;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		ll in,fin;
		cin>>n>>a>>p;
		for(int i=0;i<a;i++){
			cin>>v[i].fst>>v[i].snd;
		}
		while(p--){
			cin>>in>>fin;
			r=0;
			for(int i=0;i<a;i++){
				if(v[i].snd<in||fin<v[i].fst)continue;
				r+=(solve(min(fin,v[i].snd)-v[i].fst+1)-solve((max(in,v[i].fst)-v[i].fst)));
				r%=MOD;
			}
			cout << r%MOD<<"\n";
		}
	}
