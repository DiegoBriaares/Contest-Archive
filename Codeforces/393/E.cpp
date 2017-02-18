#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define MAXP 9223372036854775807
#define MAX 150002
#define MAXN 32
ll r=(MAXP);
bool eratos[MAX];
vector<ll>primos;
ll memo[MAX][MAXN];
ll pot[MAXN][MAXN];
int log_x(ll y){
	ll x=92233720;
	int res=0;
	while(x){
		res++;
		x/=y;
	}
	return res+1;
}
void criba(){
	for(int i=2;i<MAX;){
		if(!eratos[i]){
			for(int j=i+i;j<MAX;j+=i){
				eratos[j]=true;
			}
		}
		if(i==2)i++;
		else i+=2;
	}
}
void get_primes(){
	for(int i=2;i<=MAX;i++){
		if(!eratos[i])primos.push_back(i);
	}
}
void get_pow(){
	for(int i=0;i<MAXN;i++){
		ll p=primos[i];
		ll loga=log_x(primos[i]);
		for(int j=1;j<=loga;j++){
			pot[i][j]=p;
			p*=primos[i];
		}
	}
}
ll dp(int n,int m){
	if(n==1)return 1;
	if(m<0||n<=0)return (MAXP);
	if(memo[n][m])return memo[n][m];
	memo[n][m]=dp(n,m-1);
	ll loga=log_x(primos[m]);
	for(int j=1;j<=loga;j++){
		if(n%(j+1)==0){
			memo[n][m]=min(memo[n][m],dp(n/(j+1),m-1)*pot[m][j]);
		}
	}
	return memo[n][m];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		criba();
		get_primes();
		get_pow();
		int n;
		cin>>n;
		for(int i=0;i<600;i++){
			for(int j=0;j<30;j++){
				r=min(r,dp(n+i,j));
			}
		}
		cout << r<<"\n";
	}
