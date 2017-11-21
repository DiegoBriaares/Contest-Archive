#include <bits/stdc++.h>
using namespace std;
#define MAX 10000002
struct nodo{
    int many;
    int cubeta[2];
};
nodo trie[MAX];
int ma;
int n,q,m=1,l;
char palabra[202];
void meter(int l){
    int pos=1;
    for(int i=0; i<l; i++){
        int letra=(palabra[i]-'0');
        if(trie[pos].cubeta[letra]==0){
            trie[pos].cubeta[letra]=++m;
        }
        pos=trie[pos].cubeta[letra];
        trie[pos].many++;
    }
}
void solve(int i,int x){
	ma=max(ma,trie[i].many*x);
	for(int j=0;j<2;j++){
		if(trie[i].cubeta[j])solve(trie[i].cubeta[j],x+1);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>palabra;
        l=strlen(palabra);
        meter(l);
    }
    solve(1,0);
    cout << ma<<"\n";
}
