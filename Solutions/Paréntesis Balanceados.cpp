#include <bits/stdc++.h>
using namespace std;
string v;
int x;
int t;
bool ok,ok2;
stack<int>pila;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>t;
		while(t--){
			cin>>v;
			x=0;
			ok=false;
			for(int i=0;i<v.size();i++){
				if(v[i]=='('){
					pila.push(1);
					continue;
				}
				else if(v[i]=='{'){
					pila.push(2);
					continue;
				}
				else if(v[i]=='['){
					pila.push(3);
					continue;
				}
				else if(pila.empty()){
					ok=true;
					cout <<"NO\n";
					break;
				}
				if(v[i]==')'&&pila.top()==1){
					pila.pop();
					continue;
				}
				if(v[i]=='}'&&pila.top()==2){
					pila.pop();
					continue;
				}
				if(v[i]==']'&&pila.top()==3){
					pila.pop();
					continue;
				}
				ok=true;
				cout <<"NO\n";
				break;
			}
			if(!ok&&pila.empty())cout <<"SI\n";
			else if(!ok) cout <<"NO\n";
			while(!pila.empty()){
				pila.pop();
			}
		}	
	}
