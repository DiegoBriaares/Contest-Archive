#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 9999999999999
ll n,k;
string v,t;
ll h[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		t="Bulbasaur";
		cin>>v;
		n=v.size();
		for(int i=0;i<n;i++){
			h[v[i]]++;
		}
		h['a']/=2;
		h['u']/=2;
		k=INF;
		for(int i=0;i<t.size();i++){
			k=min(k,h[t[i]]);
		}
		cout << k<<"\n";
	}
