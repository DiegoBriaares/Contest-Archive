#include <bits/stdc++.h>
using namespace std;
#define MAX 301002
#define ll long long
#define MOD 1000000007
ll n,k;
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		ll a=1,b=1000000;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0,j=n-1;i<=j;){
			ll x=abs(a-v[i]),y=abs(b-v[j]);
			if(x<y)i++;
			else if(x>y)j--;
			else i++,j--;
			ll mini=min(x,y);
			a+=mini;
			b-=mini;
			k+=mini;
		}
		cout << k<<"\n";
	}
