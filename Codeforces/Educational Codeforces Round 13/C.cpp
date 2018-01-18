#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
ll n,a,b,p,q;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>a>>b>>p>>q;
		ll maxi=((a*b)/__gcd(a,b));
		ll both=(n/(maxi));
		ll red=(n/a)-both;
		ll blue=(n/b)-both;
		if(p>q){
			cout << ((red*p)+(blue*q)+(both*p))<<"\n";
		}
		else cout << ((red*p)+(blue*q)+(both*q))<<"\n";
	}
