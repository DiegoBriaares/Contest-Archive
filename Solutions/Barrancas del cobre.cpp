#include <bits/stdc++.h>
using namespace std;
#define MAX 50002
int v[MAX];
int n,k;
int s=0;
int r=0;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=1;i<k;i++)s+=(v[i]-v[i-1]);
		r=s;
		for(int i=(n-k),j=2;i>0;i--,j++){
			s-=(v[j-1]-v[j-2]);
			s+=(v[(j+k-2)]-v[(j+k-3)]);
			r=max(r,s);
		}
		cout << r<<"\n";
	}
