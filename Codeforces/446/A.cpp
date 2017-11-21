#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n,k,s;
ll v[MAX];
ll v2[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
			for(int i=0;i<n;i++){
			cin>>v[i];
			s+=v[i];
		}
		for(int i=0;i<n;i++){
			cin>>v2[i];
		}
		sort(v2,v2+n);
		if(s<=v2[n-1]+v2[n-2])cout <<"YES\n";
		else cout << "NO\n";
	}
