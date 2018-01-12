#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 99999999999
ll n,k;
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v,v+n);
		ll mini=INF,cant=0;
		for(int i=1;i<n;i++){
			mini=min(mini,v[i]-v[i-1]);
		}
		for(int i=1;i<n;i++){
			if(v[i]-v[i-1]==mini)cant++;
		}
		cout << mini<<" "<<cant<<"\n";
	}
