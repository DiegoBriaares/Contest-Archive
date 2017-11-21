#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
int n,c;
char m[MAX][MAX];
bool v[MAX][MAX];
void dfs(int i,int j){
	if(i<0||j<0||i>=n||j>=c||v[i][j]||m[i][j]=='#')return;
	v[i][j]=true;
	dfs(i+1,j);
	dfs(i-1,j);
	dfs(i,j+1);
	dfs(i,j-1);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		int i,j;
		int r=0;
		for(i=0;i<n;i++){
			for(j=0;j<c;j++){
				cin>>m[i][j];
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<c;j++){
				if(m[i][j]=='.'&&!v[i][j]){
					r++;
					dfs(i,j);	
				}
			}
		}
		cout << r<<"\n";
	}
