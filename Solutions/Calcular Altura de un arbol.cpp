#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int n;
int r;
int raiz;
vector<int>hijos[MAX];
void graph(int nodo,int lvl){
	r=max(r,lvl);
	for(int i=0;i<hijos[nodo].size();i++){
		graph(hijos[nodo][i],lvl+1);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			int j;
			cin>>j;
			if(j==-1)raiz=i;
			else hijos[j].push_back(i);
		}
		graph(raiz,1);
		cout << r<<"\n";
	}
