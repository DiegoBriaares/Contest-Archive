#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
int v[MAX];
int memo[MAX];
int r[MAX];
int p=1;
int pila[MAX];
int n,res;
bool cicle;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int i,j,k,g,h;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>v[i];
		}
		for(i=1;i<=n;i++){
			if(!memo[i]){
				for(j=i;!memo[j];){
					memo[j]=i;
					pila[p++]=j;
					j=v[j];
				}
				if(memo[j]==i){ //Nuevo ciclo
				k=1;
				for(g=p-1;g>=1;g--){
					if(pila[g]==j)break;
					k++;	
				}
				cicle=true;
					while(p>=1){
						p--;
						if(cicle)r[pila[p]]=k;
						else r[pila[p]]=r[v[pila[p]]]+1;
						if(pila[p]==j)cicle=false;
					}
				}
				else {
					while(p>=1){
						p--;
						r[pila[p]]=r[v[pila[p]]]+1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)res=max(res,r[i]);
		cout <<res<<"\n";	
	}
