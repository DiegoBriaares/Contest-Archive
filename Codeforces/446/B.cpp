#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
ll n,k;
ll v[MAX];
stack<ll>pila;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		for(int i=1;i<=n;i++){
			while(!pila.empty()&&(i-v[i])<=pila.top()){
				k++;
				pila.pop();
			}
			pila.push(i);
		}
		cout << n-k<<"\n";
	}
