#include <bits/stdc++.h>
using namespace std;
#define MAX 102
int n,r;
int v[MAX];
int tree[100002];
int memo[MAX][100002];
void dp(int i,int s){
	if(!tree[s]){
		r+=s;
		tree[s]=true;
	}
	if(i<0)return;
	if(memo[i][s])return;
	memo[i][s]=true;
	dp(i-1,s);
	dp(i-1,s-v[i]);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			r=0;
			int s=0;
			memset(memo,0,sizeof(memo));
			memset(tree,0,sizeof(tree));
			cin>>n;
			for(int i=0;i<n;i++){
				cin>>v[i];
				s+=v[i];
			}
			dp(n-1,s);
			cout << r<<"\n";
		}	
	}
