#include <bits/stdc++.h>
using namespace std;	
#define MAX 1000003
#define ll long long
ll n,k,j,g,t;
int v[MAX];
	int solve (int x,int y){
		int r=0;
		while(x){
			x/=y;
			r+=x;
		}
		return r;
	}
	void criba(){
		v[1]=1;
		for(int i=2;i<=MAX;i++){
			if(!v[i]){
				for(int j=i+i;j<=MAX;j+=i){
					v[j]=1;
				}
			}
		}
	}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		criba();
		cin>>t;
		for(int rep=0;rep<t;rep++){
			cin>>n>>k;
			g=1;
			for(int i=1;i<=n;i++){
				if(!v[i]){
					g*=pow(i,solve(n-1,i)-solve(n-k,i)-solve(k-1,i));
				}
			}
			cout << g<<"\n";
		}
	}
