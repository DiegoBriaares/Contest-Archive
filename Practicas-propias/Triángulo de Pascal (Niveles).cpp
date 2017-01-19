#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll n,m,r;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			r=0;
			cin>>n>>m;
			for(int i=n;i<=m;i++){
				r+=(1ULL<<i);
			}
			cout <<r<<"\n";
		}
	}
