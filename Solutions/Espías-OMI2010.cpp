#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
int v[MAX],r[MAX],pila[MAX],in=1,n,memo[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		int i,j,k,g,h;
		for(i=1;i<=n;i++){
			cin>>j;
			v[i]=j;
		}
		for(i=1;i<=n;i++){
			if(!memo[i]){
				for(j=i;!memo[j];){
					memo[j]=i;
					pila[in++]=j;
					j=v[j];
				}
				if(memo[j]==i){  //Terminas el ciclo (nuevo)
					//Nuevo ciclo
					int k=1;
					for(g=in-1;g>=1;g--){ //Contamos largo del ciclo.
						if(pila[g]==j)break;
						k++;
					}
					bool cicle=true;
					while(in>=1){  
						in--;
						if(cicle)r[pila[in]]=k;//Le asignamos a todos los valores de la pila el largo del ciclo
						else r[pila[in]]=r[v[pila[in]]]+1; //Y a los que ya no son parte del ciclo, actualizamos sus valores
						if(pila[in]==j)cicle=false; 
					}
				}
				else {  //Ya teniamos contabilizado el ciclo, asi que actualizamos los valores.
					while(in>=1){
						in--;
						r[pila[in]]=r[v[pila[in]]]+1;
					}
				}
			}
		}
		k=0;
		for(i=1;i<=n;i++){
			k=max(k,r[i]);
		}
		cout << k<<"\n";
	}
