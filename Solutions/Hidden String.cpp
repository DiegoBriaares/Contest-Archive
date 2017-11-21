#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P 407
#define MOD 1000000007
int n;
ll pot;
set<ll>S;
void power(){
	pot=1;
	for(int i=0;i<n;i++){
		pot*=P;
	}
}
ll hashing(string v){
	ll r=0;
	for(int i=0;i<v.size();i++){
		r*=P;
		r+=(ll)(v[i]);
	}
	return r;
}
void memorize(string v){
	ll h=0;
	for(int i=0;i<v.size();i++){
		h*=P;
		h+=(ll)(v[i]);
		if(i>=n){
			h-=(pot*v[i-n]);
		}
		if(i>=n-1){
			S.insert(h);
		}
	}
}
bool solve(string v){
	ll h=0;
	for(int i=0;i<v.size();i++){
		h*=P;
		h+=(ll)(v[i]);
		if(i>=n){
			h-=(pot*v[i-n]);
		}
		if(i>=n-1){
			if(S.find(h)!=S.end())return true;
		}
	}
	return false;
}
	int main (){
		string a,b;
		while(cin>>a){
			S.clear();
			cin>>b>>n;
			power();
			memorize(a);
			if(solve(b))cout <<"yes\n";
			else cout <<"no\n";
		}
		
	}
