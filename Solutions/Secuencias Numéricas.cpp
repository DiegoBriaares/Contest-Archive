#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
int v[MAX],n,v2[MAX];
stack<int>pila;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		int i,j,k,g,h;
		for(i=1;i<=n;i++){
			cin>>v[i];
			v2[i]=-1;
			if(i==1)pila.push(i);
			else {
				if(!pila.empty()){
				while(v[i]>v[pila.top()]&&!pila.empty()){
					v2[pila.top()]=i;
					pila.pop();
					if(pila.empty())break;
				}
				}
				pila.push(i);
			}
		}
		for(i=1;i<=n;i++)cout << v2[i]<<" ";
	}
