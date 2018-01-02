#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
#define ll long long
#define MOD 1000000007
ll l,r;
string v;
ll h[52][MAX];
ll fact[MAX];
ll rfact[MAX];
ll power(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    if (y & 1) {
        return power(x, y - 1) * x % MOD;
    } else {
        ll tmp = power(x, y / 2);
        return tmp * tmp % MOD;
    }
}
void initialize(){
	for(int i=0;i<v.size();i++){
		for(int j=0;j<26;j++){
			h[j][i+1]=h[j][i];
		}
		h[v[i]-'a'][i+1]++;
	}
	fact[0]=1LL;
	rfact[0]=1LL;
	for(int i=1;i<MAX;i++){
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
		rfact[i] = power(fact[i], MOD - 2);
	}
}
ll answerQuery(int l,int r){
	ll un,par,s=1LL;
	un=par=0;
	for(int i=0;i<26;i++){
		par+=((h[i][r]-h[i][l-1])/2);
		s*=rfact[((h[i][r]-h[i][l-1])/2)];
		s%=MOD;
		if((h[i][r]-h[i][l-1])%2!=0)un++;
	}
	s*=fact[par];
	s%=MOD;
	s*=max(1LL,un);
	s%=MOD;
	return s;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>v;
		initialize();
		int q;
		cin>>q;
		while(q--){
			cin>>l>>r;
			cout << answerQuery(l,r)<<"\n";
		}
		
	}
