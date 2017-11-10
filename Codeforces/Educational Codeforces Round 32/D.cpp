#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n,K;
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>K;
		K=min(n,K);
		ll res=0;
		res++;	
		ll fact=1LL,aux=1LL,aux2;
		for(int k = 1; k <= K; k++){
			fact*=k;
			aux*=(n-k+1);
			aux2=(ll)aux/fact;
	
			res+=aux2*(k==1?0:k==2?1:k==3?2:9);
		} cout << res<<"\n";
	}
