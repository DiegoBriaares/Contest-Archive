#include <bits/stdc++.h>
using namespace std;
#define MAX 1102
bool ok;
string a,b;
int memo[MAX][MAX];
int dp(int i,int j){
	if(i==a.size()&&b.size()==j){
		ok=true;
		return memo[i][j]=0;
	}
	if(memo[i][j]!=-1)return memo[i][j];
	if(a[i]>='A'&&a[i]<='Z'){
		if(a[i]!=b[j])return memo[i][j]=-100000;
		return memo[i][j]=dp(i+1,j+1)+1;
	}
	else {
		memo[i][j]=dp(i+1,j);
		char aux=(a[i]-'a')+'A';
		if(aux==b[j])memo[i][j]=max(memo[i][j],1+dp(i+1,j+1));
		return memo[i][j];
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int q;
		cin>>q;
		while(q--){
			cin>>a;
			cin>>b;
			int aux=0;
			for(int i=0;i<a.size();i++){
				if(a[i]>='A'&&a[i]<='Z')aux++;
			}
			if(aux>b.size()){
				cout << "NO\n";
				continue;
			}
			memset(memo,-1,sizeof(memo));
			ok=false;
			dp(0,0);
			if(ok)cout << "YES\n";
			else cout <<"NO\n";
		}
	}
