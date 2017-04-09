#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int r=(1<<30);
int n,m;
int memo[MAX];
pair<int,int>aux,aux2;
queue<pair<int,int> >cola;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		aux=make_pair(n,0);
		cola.push(aux);
		while(!cola.empty()){
			aux=cola.front();
			cola.pop();
			if(aux.first>=m){
				if(aux.second+(aux.first-m)<r){
					r=aux.second+(aux.first-m);
				}
				continue;
			}
			if(aux.second>=r)continue;
			if(memo[aux.first])continue;
			memo[aux.first]=true;
			aux2=make_pair(aux.first*2,aux.second+1);
			cola.push(aux2);
			aux2=make_pair(aux.first-1,aux.second+1);
			cola.push(aux2);
		}
		cout << r<<"\n";
	}
