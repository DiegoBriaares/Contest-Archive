#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int n,k;
int r,g;
int v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		if(n==k){
			cout << -1<<"\n";
			return 0;
		}
		for(int i=1;i<=n;i++){
			v[i]=i;
		}
		g=n-1;
		if(n%2==k%2){
			swap(v[1],v[n]);
			g--;
		}
		for(r=2;g>k;r+=2,g-=2){
			swap(v[r],v[r+1]);
		}
		for(int i=1;i<=n;i++)cout << v[i]<<" ";
	}
