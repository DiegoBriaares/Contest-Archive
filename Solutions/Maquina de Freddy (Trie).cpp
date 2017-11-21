#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
int n,c;
int m=1;
string v;
bool ok;
struct node {
	bool done;
	int sons[3];
};
node trie[MAX];
void add(){
	int pos=1;
	for(int i=0;i<v.size();i++){
		int l=(v[i]-'a');
		if(!trie[pos].sons[l])trie[pos].sons[l]=++m;
		pos=trie[pos].sons[l];
	}
	trie[pos].done=true;
}
int l(int x){
	return (v[x]-'a');
}
void solve(int i,int pos,int k){
	if(ok)return;
	if(i==v.size()){
		if(k)ok=trie[pos].done;
		return;
	}
	if(!k){
		for(int j=0;j<3;j++){
			if(trie[pos].sons[j])solve(i+1,trie[pos].sons[j],k+(j==l(i)?0:1));
		}
	}
	else if(trie[pos].sons[l(i)])solve(i+1,trie[pos].sons[l(i)],k);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		for(int i=0;i<n;i++){
			cin>>v;
			add();
		}
		for(int i=0;i<c;i++){
			cin>>v;
			ok=false;
			solve(0,1,0);
			if(ok)cout << "SI\n";
			else cout <<"NO\n";
		}
	}
