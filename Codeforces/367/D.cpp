#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
#define ll long long
ll q;
struct node {
	int sons[2][2];
};
int m=1;
node trie[MAX*35];
void add(ll x){
	string v="";
	for(int i=30;i>=0;i--){
		if((x&(1LL<<i)))v+='1';
		else v+='0';
	}
	int pos=1;
	for(int i=0;i<v.size();i++){
		bool l=v[i]-'0';
		if(!trie[pos].sons[l][0])trie[pos].sons[l][0]=++m;
		trie[pos].sons[l][1]++;
		pos=trie[pos].sons[l][0];
	}
}
void del(ll x){
	string v="";
	for(int i=30;i>=0;i--){
		if((x&(1LL<<i)))v+='1';
		else v+='0';
	}
	int pos=1;
	for(int i=0;i<v.size();i++){
		int l=v[i]-'0';
		if(!trie[pos].sons[l][0])return;
		trie[pos].sons[l][1]--;
		pos=trie[pos].sons[l][0];
	}
}
ll solve(ll x){
	string v="";
	for(int i=30;i>=0;i--){
		if((x&(1LL<<i)))v+='1';
		else v+='0';
	}
	ll sum=0;
	int pos=1;
	for(int i=0,j=30;i<v.size();i++,j--){
		bool l=v[i]-'0';
		if(!trie[pos].sons[l][0]&&!trie[pos].sons[!l][0])return x;
		if(trie[pos].sons[!l][1]){
			sum+=(1LL<<j);
			pos=trie[pos].sons[!l][0];
		}
		else {
			pos=trie[pos].sons[l][0];
		}
	}
	return sum;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>q;
		add(0);
		while(q--){
			char op;
			ll x;
			cin>>op>>x;
			if(op=='+'){
				add(x);
			}
			else if(op=='-'){
				del(x);	
			}
			else {
				cout << solve(x)<<"\n";
			}
		}	
	}
