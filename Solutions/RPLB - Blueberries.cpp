#include <bits/stdc++.h>
using namespace std;
#define MAX 1003
int v[MAX],k,n,may;
bool memo[MAX][MAX];
void dp(int i,int m){
	if(m>k)return;
	if(m>may)may=m;
	if(memo[i][m])return;
	memo[i][m]=true;
	if(!memo[i+1][m]&&i<n-1)dp(i+1,m);
	m+=v[i];
	if(m>k)return;
	if(m>may)may=m;
	if(i<n-2&&!memo[i+2][m])dp(i+2,m);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t,rep;
		for(cin>>t,rep=1;rep<=t;rep++){
			memset(memo,false,sizeof(memo));
			int i,j,g,h;	
			may=0;
			cin>>n>>k;
			for(i=0;i<n;i++){
				cin>>v[i];
			}
			dp(0,0);
			cout <<"Scenario #"<<rep<<": "<< may<<"\n";
		}
	}
