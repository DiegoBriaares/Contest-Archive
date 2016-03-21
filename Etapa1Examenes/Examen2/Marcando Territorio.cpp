#include <bits/stdc++.h>
using namespace std;
#define MAX 12
bool v[MAX][MAX];
int n,m,r=0;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
void dfs(int i,int j,int s,int i2,int j2){
	if(i>n||j>m||i<1||j<1||v[i][j]){
		s--;
		r=max(r,s);
		return;
	}
	for(int uso=0;uso<4;uso++){
		if(!(i+dx[uso]==i2&&j+dy[uso]==j2)&&v[i+dx[uso]][j+dy[uso]]){
			s--;
			r=max(r,s);
			return;
		}
	}
	v[i][j]=true;
	for(int uso=0;uso<4;uso++){
		dfs(i+dx[uso],j+dy[uso],s+1,i,j);
	}
	v[i][j]=false;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		dfs(1,1,1,0,0);
		memset(v,false,sizeof(v));
		dfs(n,1,1,0,0);
		memset(v,false,sizeof(v));
		dfs(1,m,1,0,0);
		memset(v,false,sizeof(v));
		dfs(n,m,1,0,0);
		cout << r<<"\n";
	}
