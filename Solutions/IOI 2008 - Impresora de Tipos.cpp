#include <bits/stdc++.h>
using namespace std;
#define MAX 500002
int n, x;
struct node {
	bool lrg,fin;
	int sons[26];
};
node trie[MAX];
int m=1;
string r="";
void add(string v){
	int pos=1;
	for(int i=0;i<v.size();i++){
		int l=(v[i]-'a');
		if(!trie[pos].sons[l])trie[pos].sons[l]=++m;
		pos=trie[pos].sons[l];
	}
	trie[pos].fin=true;
}
void add_larger(string v){
	int pos=1;
	for(int i=0;i<v.size();i++){
		int l=(v[i]-'a');
		if(!trie[pos].sons[l])trie[pos].sons[l]=++m;
		pos=trie[pos].sons[l];
		trie[pos].lrg=true;
	}
}
void dfs(int nodo){
	if(trie[nodo].fin){
		r+=('P');
	}
	int uso=-1;
	for(int i=0;i<26;i++){
		if(trie[trie[nodo].sons[i]].lrg){
			uso=i;
		}
		else if(trie[nodo].sons[i]){
			r+=(i+'a');
			char uso2=i+'a';
			dfs(trie[nodo].sons[i]);
			r+=('-');
		}
	}
	if(uso!=-1){
		r+=(uso+'a');
		dfs(trie[nodo].sons[uso]);
	}
}
	int main (){
		cin>>n;
		string v,maxi;
		int maxi2=0;
		for(int i=0;i<n;i++){
			cin>>v;
			add(v);
			if(v.size()>maxi2){
				maxi2=v.size();
				maxi=v;
			}
		}
		add_larger(maxi);
		dfs(1);
		cout << r.size() <<"\n";
		for(int i=0;i<r.size();i++){
			cout <<r[i]<<"\n";
		}
	}
