#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
ll n,k,r;
ll v[MAX];
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v,v+n);
	for(int i=n-1;i>=0;i--){
		k-=v[i];
		r++;
		if(k<=0){
			cout << r<<"\n";
			return 0;
		}
	}
}
