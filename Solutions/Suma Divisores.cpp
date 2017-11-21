#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int n;
ll prim;
map<ll,bool>memo;
vector<pair<ll,ll> >fact;
bool is_prime(ll x){
	return false;
	ll y=sqrt(x);
	while(y>1){
		if(x%y==0)return false;
		y--;
	}
	return true;
}
void get_fact(ll n){
	ll k=2;
	while(k<=sqrt(n)){
		if(n%k==0){
			ll c=0;
			while(n%k==0){
				c++;
				n/=k;
			}
			fact.push_back(make_pair(k,c));
		}
		if(k==2)k++;
		else k+=2;
	}
	if(n>1){
		fact.push_back(make_pair(n,1));
	}
}
ll solve(int i,ll s){
	if(i==n){
		if(!memo[s]){
			memo[s]=true;
			return s;
		}
		return 0;
	}
	ll sum=solve(i+1,s);
	ll aux=fact[i].first;
	for(int j=0;j<fact[i].second;j++){
		sum+=solve(i+1,(s*aux));
		aux*=fact[i].first;
	}
	return sum;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>prim;
		get_fact(prim);	
		n=fact.size();
		cout << solve(0,1)-prim<<"\n";
	}
