#include <bits/stdc++.h>
using namespace std;
#define MAX 1000003
int n,v[MAX],memo[MAX],res=0,r[MAX],pila[MAX],in=1;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		int j;
		for(int i=1;i<=n;i++)cin>>v[i];
		for(int i=1;i<=n;i++){
			if(!memo[i]){
				for(j=i;!memo[j];){
					memo[j]=i;
					pila[in++]=j;
					j=v[j];
				}
				if(memo[j]==i){
					int uso=1,cicle=1;
					for(int g=in-1;g>=1;g--){
						if(pila[g]==j)break;
						uso++;
					}
					while(in>=1){
						in--;
						if(cicle)r[pila[in]]=uso;
						else r[pila[in]]=r[v[pila[in]]]+1;
						res=max(res,r[pila[in]]);
						if(pila[in]==j)cicle=0;
					}
				}
				else {
					while(in>=1){
						in--;
						r[pila[in]]=r[v[pila[in]]]+1;
						res=max(res,r[pila[in]]);
					}
				}
			}
		}
		cout << res<<"\n";
	}
