#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll int
ll n,s,c,r;
ll v[MAX];
ll ord[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>s>>c;
		for(int i=0;i<c;i++){
			cin>>v[i];
			if(i){
				ord[i-1]=v[i]-v[i-1];
			}
		}
		n--;
		sort(v,v+c);
		sort(ord,ord+c-1);
		reverse(ord,ord+c-1);
		for(int i=0;i<n&&i<c-1;i++){
			r+=ord[i]-1;
		}
		cout << v[c-1]-v[0]+1-r<<"\n";
	}
