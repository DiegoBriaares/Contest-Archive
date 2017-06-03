#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define MAXN 15
struct node {
	bool fin;
	int sons[4];
};
int n;
int m=1;
int len,res;
int arr[MAX];
node trie[MAX*MAXN];
void add(string v){
	int pos=1;
	for(int i=0;i<=len;i++){
		int l=(v[i]-'0');
		if(!trie[pos].sons[l])trie[pos].sons[l]=++m;
		pos=trie[pos].sons[l];
	}
	trie[pos].fin=true;
}
int maxi(int a,int b){
	return (a>b?a:b);
}
int dp(int pot,int pos,int idx){
	if(pot>len)return 0;
	if(trie[pos].fin||trie[idx].fin)return -(1<<30);
	int r=-(1<<30);
	if(trie[pos].sons[1]&&trie[idx].sons[0]&&trie[pos].sons[0]&&trie[idx].sons[1])r=maxi(r,(1<<(len-pot))+maxi(r,maxi(dp(pot+1,trie[pos].sons[1],trie[idx].sons[0]),dp(pot+1,trie[pos].sons[0],trie[idx].sons[1]))));
	else if(trie[pos].sons[1]&&trie[idx].sons[0])r=maxi(r,(1<<(len-pot))+dp(pot+1,trie[pos].sons[1],trie[idx].sons[0]));
	else if(trie[pos].sons[0]&&trie[idx].sons[1])r=maxi(r,(1<<(len-pot))+dp(pot+1,trie[pos].sons[0],trie[idx].sons[1]));
	else {
		if(trie[pos].sons[0]){
			r=maxi(r,dp(pot+1,trie[pos].sons[0],trie[idx].sons[0]));
		}
		else {
			r=maxi(r,dp(pot+1,trie[pos].sons[1],trie[idx].sons[1]));
		}
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			for(int j=0;j<=MAXN;j++){
				if((arr[i]&(1<<j)))len=maxi(len,j);
			}
		}
		for(int i=0;i<n;i++){
			string aux="";
			for(int j=0;j<=len;j++){
				if((arr[i]&(1<<j)))aux+="1";
				else aux+="0";
			}
			reverse(aux.begin(),aux.end());
			add(aux);
		}
		cout << dp(0,1,1)<<"\n";
	}
