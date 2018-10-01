#include <bits/stdc++.h>
using namespace std;
#define MAX 112
#define ll long long

ll V[MAX][MAX],R,C,v[MAX][MAX];

int dfs(ll i, ll j){
	v[i][j]=1;
	if (V[i+1][j] == V[i][j] && !v[i+1][j]) dfs(i+1,j);
	if (V[i-1][j] == V[i][j] && !v[i-1][j]) dfs(i-1,j);
	if (V[i][j+1] == V[i][j] && !v[i][j+1]) dfs(i,j+1);
	if (V[i][j-1] == V[i][j] && !v[i][j-1]) dfs(i,j-1);
}

ll recorrido(){
	ll cont=0;
	
	for (ll i=1; i<= R; i++){
		for (ll j=1; j<=C; j++){
			if (!v[i][j]){
				cont++;
				dfs(i,j);
			}
		}
	}
	return cont;
}

int main () {
	int a,b,x,y,c,flag,signo;
	
  	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	cout.tie(0);
  	
  	while(cin>>R){
  		cin>>C;
  		for (ll i=1; i<=R; i++){
  			for (ll j=1; j<=C; j++){
  				cin>>V[i][j];	
			}
		}
		c=0;
		for (ll i=1; i<=R+1; i++){
			flag=0;
			for (ll j=1; j<=C; j++){
				x=min(V[i-1][j],V[i][j]);
				y=max(V[i-1][j],V[i][j]);
				if (x != y){
					if (flag == 0 || (V[i-1][j] == x) != signo || x>=b || y<=a) c++;
					a=x;
					b=y;
					signo=V[i-1][j] == x;
					flag=1;
				}
				else flag=0;
			}
		}
		for (ll j=1; j<=C+1; j++){
			flag=0;
			for (ll i=1; i<=R; i++){
				x=min(V[i][j-1],V[i][j]);
				y=max(V[i][j-1],V[i][j]);
				if (x != y){
					if (flag == 0 || (V[i][j-1] == x) != signo || x>=b || y<=a) c++;
					a=x;
					b=y;
					signo=V[i][j-1] == x;
					flag=1;
				}
				else flag=0;
			}
		}
		cout<<c+recorrido()+1<<'\n';
		memset(v,0,sizeof(v));
		memset(V,0,sizeof(V));
	}
}
