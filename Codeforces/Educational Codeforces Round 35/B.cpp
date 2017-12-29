#include <bits/stdc++.h>
using namespace std;
#define MAX 1000102
#define ll long long
#define MOD 1000000007
ll n,a,b;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>a>>b;
		ll in=1,fin=300,la=1;
		for(int i=1;i<n;i++){
			la=max(la,min((a/i),(b/(n-i))));
		}
		cout <<la<<"\n";
	}
