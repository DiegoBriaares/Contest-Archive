#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll r;
ll n,t,f;
ll v[MAX];
bool solve(ll x){
	ll a=t,b=f;
	for(int i=0;i<n;i++){
		a+=v[i];
		b+=x;
		if(a>=b)return false;
	}
	return true;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>t>>f;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}	
		ll in=0,fin=(1<<30),mid;
		while(in<fin){
			mid=(in+fin)/2;
			if(solve(mid)){
				fin=mid;
			}
			else in=mid+1;
		}
		cout << fin<<"\n";
	}
