#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define primo first
#define expo second
ll a,b;
vector<ll>divi;
map<ll,bool>memo;
vector<pair<ll,ll> >fact;
bool is_prime(ll x){
	ll y=sqrt(x);
	while(y>1){
		if(x%y==0)return false;
		y--;
	}
	return true;
}
void get_fact(ll n){
	ll k=2;
	while(k<=n){
		if(n%k==0){
			int c=0;
			while(n%k==0){
				c++;
				n/=k;
			}
			fact.push_back(make_pair(k,c));
		}
		else if(is_prime(n)){
			fact.push_back(make_pair(n,1));
			break;
		}
		if(k==2)k++;
		else k+=2;
	}
}
void get_div(int i,ll p){
	if(i==fact.size()){
		if(!memo[p]){
			memo[p]=true;
			divi.push_back(p);
		}
		return;
	}
	ll aux=fact[i].first;
	get_div(i+1,p);
	for(int j=0;j<fact[i].second;j++){
		get_div(i+1,p*aux);
		aux*=fact[i].first;
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>a>>b;
		ll mcd=__gcd(a,b);
		get_fact(mcd);
		get_div(0,1LL);
		sort(divi.begin(),divi.end());
		for(int i=0;i<divi.size();i++){
			cout << divi[i]<<" "<<(a/divi[i])<<" "<<(b/divi[i])<<"\n";
		}
	}
