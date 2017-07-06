#include <bits/stdc++.h>
using namespace std;
#define MAX 502
int n;
int v[MAX];
struct node {
	int val;
	int cont;
};
node memo[MAX][MAX];
node dp(int i,int j){
	if(i==j){
		node aux;
		aux.val=v[i];
		aux.cont=0;
		return aux;
	}
	if(memo[i][j].val)return memo[i][j];
	node aux;
	aux.cont=aux.val=(1<<30);
	for(int k=i;k<j;k++){
		node uso=dp(i,k);
		node uso2=dp(k+1,j);
		if(uso.cont+uso2.cont+max(uso.val,uso2.val)<aux.cont){
			aux.cont=uso.cont+uso2.cont+max(uso.val,uso2.val);
			aux.val=uso.val+uso2.val;
		}
	}
	memo[i][j]=aux;
	//cout << "RES: "<<i<<" "<<j<<" VAL-> "<<memo[i][j].val<<" SUM-> "<<memo[i][j].cont<<"\n";
	return memo[i][j];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		cout << dp(0,n-1).cont<<"\n";
	}
