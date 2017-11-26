#include <bits/stdc++.h>
using namespace std;
#define MAX 10002
int n,k,s;
int v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x]=max(v[x],y);
		}
		for(int i=k;i>=0;i--,s++){
			s=max(s,v[i]);
		}
		cout <<s-1<<"\n";
	}
