#include <bits/stdc++.h>
using namespace std;
#define MAX 2500002
struct node {
	bool done;
	int hijos[26];
};
node trie[MAX];
string v;
int n,m=1,k;
bool ok;
void add(){
	int pos=1;
	for(int i=0;i<v.size();i++){
		int l=(v[i]-'a');
		if(!trie[pos].hijos[l])trie[pos].hijos[l]=++m;
		pos=trie[pos].hijos[l];
	}
	trie[pos].done=true;
}
void solve(int i,string r){
	if(trie[i].done){
		ok=true;
		cout <<r<<"\n";
	}
	int pos=i;
	if(i==1){
		for(int j=0;j<v.size();j++){
			int l=(v[j]-'a');
			if(!trie[pos].hijos[l])return;
			r+=v[j];
			pos=trie[pos].hijos[l];
		}
		for(int j=0;j<26;j++){
			char uso=j+'a';
			if(trie[pos].hijos[j])solve(trie[pos].hijos[j],r+uso);
		}
	}
	else {
		for(int j=0;j<26;j++){
			char uso=j+'a';
			if(trie[pos].hijos[j])solve(trie[pos].hijos[j],r+uso);
		}
	}
	
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v;
			add();
		}
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>v;
			ok=false;
			cout <<"Case #"<<i<<":\n";
			solve(1,"");
			if(!ok)cout <<"No match.\n";
		}	
	}
