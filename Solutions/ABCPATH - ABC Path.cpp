#include <bits/stdc++.h>
using namespace std;
#define MAX 55
#define state pair<int,int>
int memo[MAX][MAX],n,c;
char v[MAX][MAX];
queue<state>cola;
int dp(int i,int j,char m){
	if(m!=v[i][j])return 0;
	if(i>=n||j>=c)return 0;
	if(memo[i][j])return memo[i][j];
	return memo[i][j]=max(max(1+dp(i+1,j,m+1),1+dp(i-1,j,m+1)),max(max(1+dp(i,j+1,m+1),1+dp(i,j-1,m+1)),max(max(1+dp(i+1,j+1,m+1),1+dp(i-1,j+1,m+1)),max(1+dp(i+1,j-1,m+1),1+dp(i-1,j-1,m+1)))));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t=1;
		cin>>n>>c;
		while(n!=0&&c!=0){
			memset(memo,0,sizeof(memo));
			int r=0;
			for(int i=0;i<n;i++)
				for(int j=0;j<c;j++){
					cin>>v[i][j];
					if(v[i][j]=='A')cola.push(make_pair(i,j));
				}
				while(!cola.empty()){
					r=max(r,dp(cola.front().first,cola.front().second,'A'));
					cola.pop();
				}
				cout << "Case "<<t<<": "<<r <<"\n";
				t++;
				cin>>n>>c;
		}
	}
