#include <bits/stdc++.h>
using namespace std;
#define MAX 1000003
int v[MAX],memo[MAX],memito[MAX],pila[MAX],r[MAX];
int in=1,n;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		int i,j,k,g,ciclo=1;
		for(i=1;i<=n;i++){
			cin>>v[i];
		}
		for(i=1;i<=n;i++){
			if(!memito[i]){
				for(j=i,k=0;!memito[j];){
					memito[j]=ciclo;
					pila[in++]=j;
					j=v[j];
				}
				if(memito[j]==ciclo){
					k=1;
				for(g=in-1;g>=1;g--){
					if(pila[g]==j)break;
					else k++;
				}
				bool incicle=true;
				while(in>1){
					in--;
					if(incicle)r[pila[in]]=k;
					else {
						r[pila[in]]=r[v[pila[in]]]+1;
					}
					if(pila[in]==j)incicle=false;
				}
				}
				else {
					while(in>1){
						in--;
						r[pila[in]]=r[v[pila[in]]]+1;
					}
				}
			}
			ciclo++;
		}
		k=0;
		//for(i=1;i<=n;i++)cout <<r[i]<<" ";
		for(i=1;i<=n;i++)k=max(k,r[i]);
		cout <<k<<"\n";
	}
