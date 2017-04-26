#include <bits/stdc++.h>
using namespace std;
#define MAX 5002
int r;
int n,k;
bool v[MAX];
int sueldos[MAX];
vector<int>sons[MAX];
int bfs(){
	memset(v,0,sizeof(v));
	memset(sueldos,0,sizeof(sueldos));
	queue<int>cola;
	v[k]=true;
	sueldos[k]=1;
	cola.push(k);//Podemos hacerlo desde el nodo superior. Es fácil demostrar que la suma es la misma.
	while(!cola.empty()){
		int boss=cola.front();
		cola.pop();
		for(int i=0;i<sons[boss].size();i++){
			int node=sons[boss][i];
			if(!v[node]){
				v[node]=true;
				sueldos[node]=sueldos[boss]+1;
				cola.push(node);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!v[i])return -1;
	}
	int s=0;
	for(int i=1;i<=n;i++){
		s+=sueldos[i];
	}
	return s;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		r=(1<<30);
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=0;j<k;j++){
				int aux;
				cin>>aux;
				sons[aux].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){  
			k=i;
			int aux=bfs();
			if(aux!=-1){
				r=min(r,aux);
			}
		}
		cout << r<<"\n";
	}
