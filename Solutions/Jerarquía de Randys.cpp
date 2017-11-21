#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
int n;
int idx;
int r[MAX];
int in[MAX];
ll bit[MAX];
int tam[MAX];
pair<ll,int>v[MAX];
vector<int>sons[MAX];
void update(int i,ll x){
	while(i<MAX){
		bit[i]+=x;
		i+=(i&-i);
	}
}
ll query(int i){
	ll s=0;
	while(i>0){
		s+=bit[i];
		i-=(i&-i);
	}
	return s;
}
void graph(int nodo){  //Hacemos el recorrido del árbol.
	in[nodo]=idx++;
	tam[nodo]++;
	for(int i=0;i<sons[nodo].size();i++){
		graph(sons[nodo][i]);
		tam[nodo]+=tam[sons[nodo][i]];
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i].first;
			v[i].second=i;
		}
		sort(v,v+n);
		reverse(v,v+n);
		for(int i=1;i<n;i++){
			int j;
			cin>>j;
			sons[j-1].push_back(i);
		}
		graph(0);
		for(int i=0;i<n;i++){
			int rango=(tam[v[i].second]);
			r[v[i].second]=(query((in[v[i].second]+rango))-query((in[v[i].second]+1)));
			update((in[v[i].second]+1),1);
		}
		for(int i=0;i<n;i++)cout << r[i]<<"\n";
	}
