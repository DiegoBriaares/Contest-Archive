#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P 9001
#define MOD 1000000007
#define par pair<ll,ll>
set<par>S;
int n;
ll pot,pot2;
void power(){
	pot=pot2=1;
	for(int i=0;i<n;i++){
		pot*=P;
		pot2*=P;
		pot2%=MOD;
	}
}
void mapear(string v){
	ll r=0,h=0;
	for(int i=0;i<v.size();i++){
		r*=P;
		r+=(ll)(v[i]);
		h*=P;
		h+=(ll)(v[i]);
		h%=MOD;
		if(i>=n){
			r-=pot*(v[i-n]);
			h-=(pot2*v[i-n]%MOD);
			if(h<0)h+=MOD;
		}
		if(i>=n-1){
			par uso=make_pair(r,h);
			S.insert(uso);
		}
	}
}
bool buscar(string v){
	ll r=0,h=0;
	for(int i=0;i<v.size();i++){
		r*=P;
		r+=(ll)(v[i]);
		h*=P;
		h+=(ll)(v[i]);
		h%=MOD;
		if(i>=n){
			r-=pot*(v[i-n]);
			h-=(pot2*v[i-n]%MOD);
			if(h<0)h+=MOD;
		}
		if(i>=n-1){
			par uso=make_pair(r,h);
			if(S.find(uso)!=S.end())return true;
		}
	}
	return false;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		string a,t;
		while(cin>>a>>t>>n){
			S.clear();
			power();
			mapear(a);
			if(buscar(t))cout <<"yes\n";
			else cout << "no\n";
		}
	}
