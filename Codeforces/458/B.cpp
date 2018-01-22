#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
ll n,k;
bool ok;
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++)cin>>v[i];
		sort(v,v+n);
		int p=1;
		for(int i=n-2;i>=0;i--){
			if(v[i]<v[i+1]){
				if(p&1)ok=true;
				p=0;
			}
			p++;
		}
		if(p&1)ok=true;
		if(ok){
			cout << "Conan\n";
		}
		else {
			cout << "Agasa\n";
		}
	}
