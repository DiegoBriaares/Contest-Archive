#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
int n,m;
bool edg[MAX][MAX];
bool dp[MAX][MAX][3];
int aum(int x){
	return ((x+1)%n);
}
int dec(int x){
	return ((x+n-1)%n);
}
void solve(int i,int j,int n){
	if(!n){
		cout << (j+1)<<"\n";
	}
	else {
		cout << (i+1)<<"\n";
	}
	if(dec(i)==j)return;
	int x=dec(i),y=aum(j);
	if(!n){
		if(edg[j][j+1]&&dp[y][i][0])solve(i,y,0);
		else solve(x,j,1);
	}
	else {
		if(edg[i][x]&&dp[j][x][1])solve(x,j,1);
		else solve(i,y,0);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			a--,b--;
			edg[a][b]=true;
			edg[b][a]=true;
		}
		for(int i=0;i<n;i++){
			dp[i][aum(i)][0]=true;
			dp[i][aum(i)][1]=true;
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<n;j++){
				if(edg[j][(j+1)%n]&&dp[(j+1)%n][(j+i)%n][0]){  //CL 0
					dp[j][(j+i)%n][0]=true;
				}
				if(edg[j][(j+i-1)%n]&&dp[(j)%n][(j+i-1)%n][1]){  //CL 1
					dp[j][(j+i)%n][0]=true;
				}
				if(edg[(j+i)%n][(j+i-1)%n]&&dp[(j)%n][(j+i-1)%n][1]){  //ACL 0
					dp[j][(j+i)%n][1]=true;
				}
				if(edg[(j+1)%n][(j+i)%n]&&dp[(j+1)%n][(j+i)%n][0]){  //ACL 1
					dp[j][(j+i)%n][1]=true;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(dp[i][i][0]){
				solve(i,i,0);
				return 0;
			}
		}
		cout << "-1\n";
	}
