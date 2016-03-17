#include <bits/stdc++.h>
using namespace std;
#define MAX 10002
int v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		
		for(int rep=0;rep<t;rep++){
			memset(v,0,sizeof(v));
			int i,j,k,n,u,g,h,y;
			cin>>n>>u;
			for(i=0;i<u;i++){
				cin>>g>>h>>y;
				v[g]+=y;
				v[h+1]-=y;
		}
		y=0;
		y=v[0];
		for(i=1;i<n;i++){
			y+=v[i];
			v[i]=y;
		}
		cin>>k;
		for(i=0;i<k;i++){
			cin>>g;
			cout << v[g]<<"\n";
		}
	}
	}
