#include <bits/stdc++.h>
using namespace std;
string v;
stack<string>pila;
queue<char>cola;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		getline(cin,v);
		int n=v.size();
		for(int i=0;i<n;){
			if(v[i]!='['){
				cola.push(v[i]);
				i++;
			}
			else {
				i++;
				string uso="";
				while(v[i]!=']'&&v[i]!='['&&i<n){
					if(v[i]!='[')uso+=(v[i]);
					i++;
				}
				pila.push(uso);
			}
		}
		while(!pila.empty()){
			cout << pila.top();
			pila.pop();
		}
		while(!cola.empty()){
			if(cola.front()!=']'&&cola.front()!='[')cout << cola.front();
			cola.pop();
		}
	}
