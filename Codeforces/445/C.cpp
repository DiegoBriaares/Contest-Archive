#include <bits/stdc++.h>
using namespace std;
#define MAX 500002
#define ll long long
ll n,r;
ll v[MAX];
int h[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
			h[v[i]]++;
		}
		for(int i=0;i<=n;i++){
			if(h[i])r++;
		}
		cout << ((n+1)-r)<<"\n";
	}
