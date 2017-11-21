#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll n,m,k;
ll solve(ll x){
	x--;
	ll r=0;
	for(int i=0;i<n;i++){
		r+=(min(x/(i+1),m));
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m>>k;
		ll in=1,fin=(n*m)+2,l,mid;
		while(in<=fin){
			mid=(in+fin)/2;
			if(solve(mid)<k){
				l=mid;
				in=mid+1;
			}
			else fin=mid-1;
		}
		cout << (l)<<"\n";
	}
