#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
ll n,k;
ll v[MAX];
bool sq(ll x){
	if(x<0)return false;
	ll y=sqrt(x);
	if(y*y==x)return true;
	return false;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++)cin>>v[i];
		sort(v,v+n);
		for(int i=n-1;i>=0;i--){
			if(!sq(v[i])){
				cout << v[i]<<"\n";
				return 0;
			}
		}
	}
