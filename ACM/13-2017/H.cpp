#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
#define ll long long
ll N,k;
ll v[MAX];

	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		while(cin>>N){
			int cont=0;
			for(int i=1;i<=N;i++){
				cin>>v[i];
			}
			for(int i=1;i<=N;i++){
				int ind=i;
				if(v[ind]!=ind){
					while(v[ind]!=ind){
						int aux=v[ind];
						v[ind]=ind;
						ind=aux;
						cont++;
					}	
					cont--;
				}
			}
			cout<<cont<<"\n";
		}
	}
