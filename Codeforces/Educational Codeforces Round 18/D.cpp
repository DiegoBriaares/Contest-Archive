#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q;
ll nodo;
string v;
void up(){
	if(nodo==((n+1)>>1))return;
	ll less=(nodo&-nodo);
	nodo|=(less<<1);
	nodo-=less;
}
void left(){
	if((nodo&1))return;
	ll less=(nodo&-nodo);
	nodo-=(less>>1);
}
void right(){
	if((nodo&1))return;
	ll less=(nodo&-nodo);
	nodo+=(less>>1);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>q;
		while(q--){
			cin>>nodo>>v;
			for(int i=0;i<v.size();i++){
				if(v[i]=='U'){
					up();
				}
				if(v[i]=='L'){
					left();
				}
				if(v[i]=='R'){
					right();
				}
			}
			cout << nodo<<"\n";
		}	
	}
