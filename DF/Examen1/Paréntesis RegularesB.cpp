#include <bits/stdc++.h>
using namespace std;
#define MAX 10000002
int m[MAX],o[MAX];
string v;
stack<int>pila;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>v;
		int i,k=0,uso;
		for(i=0;i<v.size();i++){
			if(v[i]=='(')pila.push(i);
			else {
				if(!pila.empty()){
					uso=(i-pila.top()+1);
					m[i]=uso;
					m[i]+=(m[i-uso]);
					o[m[i]]++;
					k=max(k,m[i]);
					pila.pop();
				}
			}
		}
		if(k==0)o[k]++;
		cout << k<<" "<<o[k]<<"\n";
	}
