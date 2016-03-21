#include <bits/stdc++.h>
using namespace std;
#define MAX 52
int n,ma;
char m[MAX][MAX];
bool v[MAX][MAX],done=false;
void dfs(int i,int j,int x,int y){
	v[i][j]=true;
	if(!(i+1==x&&j==y)&&i+1<n){
		if(m[i][j]==m[i+1][j]){
			if(v[i+1][j]){
			done=true;
			return;
		}
		dfs(i+1,j,i,j);
		}
		if(done)return;
	}
	if(!(i-1==x&&j==y)&&i-1>=0){
		if(m[i][j]==m[i-1][j]){
			if(v[i-1][j]){
			done=true;
			return;
		}
		dfs(i-1,j,i,j);
		}
		if(done)return;
	}
	if(!(i==x&&j+1==y)&&j+1<ma){
		if(m[i][j]==m[i][j+1]){
			if(v[i][j+1]){
			done=true;
			return;
		}
		dfs(i,j+1,i,j);
		}
		if(done)return;
	}
	if(!(i==x&&j-1==y)&&j-1>=0){
		if(m[i][j]==m[i][j-1]){
			if(v[i][j-1]){
			done=true;
			return;
		}
		dfs(i,j-1,i,j);
		}
		if(done)return;
	}
	if(done)return;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>ma;
		for(int i=0;i<n;i++){
			for(int j=0;j<ma;j++){
				cin>>m[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<ma;j++){
				if(!v[i][j]){
					dfs(i,j,-1,-1);
				}
				if(done)break;
			}
		}
		if(done)cout << "Yes\n";
		else cout <<"No\n";
	}
