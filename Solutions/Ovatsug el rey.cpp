#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
#define ll long long
ll n,t;
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>t;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}	
		t%=n;
		for(int i=t;i<n;i++){
			cout << v[i]<<" ";
		}
		for(int i=0;i<t;i++){
			cout << v[i]<<" ";
		}
	}
