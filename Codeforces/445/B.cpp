#include <bits/stdc++.h>
using namespace std;
#define MAX 500002
#define ll long long
ll n,k;
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
		for(int i=0;i<n;i++){
			h[v[i]]--;
			if(!h[v[i]]){
				cout << v[i]<<"\n";
				return 0;
			}
		}
	}
