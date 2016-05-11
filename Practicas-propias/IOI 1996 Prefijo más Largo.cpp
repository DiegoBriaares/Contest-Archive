#include <bits/stdc++.h>
using namespace std;
#define MAX 500002
struct nodo {
	bool esta;
	int cubeta[26];
};
nodo trie[MAX];
int n,m=1;
int dp[MAX];
string base;
void meter(string v){
	int pos=1;
	for(int i=0;i<v.size();i++){
		int letra=(v[i]-'A');
		if(!trie[pos].cubeta[letra]){
			trie[pos].cubeta[letra]=++m;
		}
		pos=trie[pos].cubeta[letra];
	}
	trie[pos].esta=true;
}
void isthere(int j){
	int pos=1;
	for(int i=j;i<base.size();i++){
		int letra=base[i]-'A';
		if(!trie[pos].cubeta[letra])return;
		pos=trie[pos].cubeta[letra];
		if(trie[pos].esta)dp[i+1]=1;
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		string a;
		for(int i=1;i<=n;i++){
			cin>>a;
			meter(a);
		}
		cin>>base;
		dp[0]=1;
		for(int i=0;i<=base.size();i++){
			if(dp[i]){
				isthere(i);
			}
		}
		for(int i=base.size();i>=0;i--){
			if(dp[i]){
				cout <<i<<"\n";
				return 0;
			}
		}
	}
