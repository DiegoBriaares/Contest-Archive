#include <bits/stdc++.h>
using namespace std;
#define MAXK 12
#define MAX 310002
#define ll long long
ll n,k;
ll sum;
ll v[MAX];
ll h[MAXK];
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>v[i];
		h[v[i]]++;
	}
	for(int i=1;i<=k;i++){
		sum+=(n-h[i])*h[i];
	}
	sum/=2LL;
	cout << sum<<"\n";
}
