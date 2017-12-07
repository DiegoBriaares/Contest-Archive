#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
#define MAXN 99999999999999999
ll n;
ll v[MAX];
bool solve(ll k){
	ll s=v[0];
	for(int i=1;i<n;i++){
		s-=k;
		if(s<0)return false;
		s+=v[i];
	}
	s-=k;
	if(s<0)return false;
	return true;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		ll in=0,fin=MAXN,la=0;
		while(in<=fin){
			ll mid=(in+fin)/2LL;
			if(solve(mid)){
				la=mid;
				in=mid+1;
			}
			else fin=mid-1;
		}
		cout << la<<"\n";
	}
