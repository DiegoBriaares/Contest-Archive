#include <bits/stdc++.h>
using namespace std;
#define MAX 110002
#define ll long long
ll n,k;
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		ll pot=1LL,p=0;
		while(p<n&&pot<=k){
			pot*=2LL;
			p++;
		}
		if(pot>k)cout << k<<"\n";
		else cout << (k%pot)<<"\n";
	}
