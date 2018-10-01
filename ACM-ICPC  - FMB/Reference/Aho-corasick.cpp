#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

typedef pair<int,int> pii;

int trie[MAX][26], fail[MAX], go[MAX][26], total;
bool end[MAX];

void insert(string &s){
	int u=0,idx;
	for (int i=0; i<s.size(); i++){
		idx=(int)(s[i]-'a');
		if (!trie[u][idx]) trie[u][idx]=total++;
		u=trie[u][idx];
	}
	end[u]=true;
}

void construye(){
	int v,u,f,fv;
	pii aux;
	queue<pii > q;
	
	for (int u=0; u<26; u++){
		if (trie[0][u]){
			v=trie[0][u];
			go[0][u]=v;
			q.push(pii(v,0));
		}
		else go[0][v]=0;
	}
	
	while (!q.empty()){
		aux=q.front();
		u=aux.first;
		f=aux.second;
		for (int t=0; t<26; t++){
			if (trie[u][t]!=0){
				v=trie[u][t];
				go[u][t]=v;
				fv=go[f][t];
				q.push(pii(v,fv));
				fail[u]=f;
			}
			else go[u][t]=go[f][t];
		}
	}
}

int main(){
	cout<<"hola";
}
