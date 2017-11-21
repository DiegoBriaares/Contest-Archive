#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define MOD 987654321
ll n,r;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		r=(n+1);
		for(int i=1;i<n;i++){
			r=(r*2ULL)%MOD;
		}
		cout << r<<"\n";
	}
