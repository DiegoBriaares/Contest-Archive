#include <bits/stdc++.h>
using namespace std;
string v,r,uso;
int memo[102][102],res=0;
int dp(int i,int j){
	if(j==uso.size()||i==v.size())return 0;
	if(memo[i][j])return memo[i][j];
	for(int k=j;k<uso.size();k++){
		if(uso[k]==v[i])return memo[i][j]=max(1+dp(i+1,k+1),dp(i+1,j));
	}
	return memo[i][j]=dp(i+1,j);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n;
		cin>>v>>n;
		for(int i=0;i<n;i++){
			cin>>uso;
			memset(memo,0,sizeof(memo));
			int uso2=dp(0,0);
		//	cout <<"R: "<<uso2<<"\n";
			if(uso2>res){
				res=uso2;
				r=uso;
			}
			else if(uso2==res){
				if(uso.size()<=r.size())r=uso;
			}
		}
		cout << r<<"\n";
	}
