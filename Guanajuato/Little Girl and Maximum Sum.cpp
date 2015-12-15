#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
long long v[2*MAX];
long long v2[2*MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		memset(v2,0,sizeof(v2));
		long long n,c,i,j,k,g,h;
		cin>>n>>c;
		for(i=1;i<=n;i++){
			cin>>v[i];
		}
		sort(v,v+n+1);
		for(i=0;i<c;i++){
			cin>>g>>h;
			v2[g]++;
			v2[h+1]--;
		}
		k=v2[1];
		for(i=2;i<=n;i++){
			k+=v2[i];
			v2[i]=k;
		}
		sort(v2,v2+n+1);
		k=0;
		for(i=1;i<=n;i++){
			k+=(v[i]*v2[i]);
		}
		cout <<k<<"\n";
	}
