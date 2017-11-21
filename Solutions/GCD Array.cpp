#include <bits/stdc++.h>
using namespace std;
#define MAX 3000002
int n,k;
int ma,me=(1<<30);
int v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(x>ma)ma=x;
			if(x<me)me=x;
			v[x]=1;
		}
		for(int i=0;i<MAX;i++){   //Forma la cubeta indexada en 1.
			v[i]=v[i]+v[i-1];
		}
		if(k>=me){  //De a fuerzas puedo formar un múltiplo de el primer elemento.
			cout << me<<"\n";
			return 0;
		}
		for(int i=me;i>=k;i--){  //Verifico cual es el a_i mayor que puedo formar tal que a_i | x para toda x en el arreglo.
			bool mal=false;
			int x=ma/i;
			x*=i;  // Con estas 2 operaciones toma el multiplo cercano al ultimo elemento.
			if(ma%i!=0)x+=i;  //Quiere decir que el multiplo es menor al mayor elemento, tonces le sumo pa que lo overlapee.
			for(int j=i;j<=x;j+=i){
				if(v[j-1]-v[j-i+k]>=1){
					mal=true;
					break;
				}
			}
			if(!mal){
				cout << i<<"\n";
				return 0;
			}
		}
	}
