#include <bits/stdc++.h>
using namespace std;
#define MAX 102
int v[MAX][MAX],n,uso;
bool m[MAX][MAX];
void dfs(int i,int j){
	if(m[i][j]||(v[i][j]%n)!=uso||i>=n||j>=n||i<0||j<0)return;
	m[i][j]=true;
	dfs(i+1,j);
	dfs(i-1,j);
	dfs(i,j+1);
	dfs(i,j-1);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		int r=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>v[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!m[i][j]){
					uso=v[i][j]%n;
					r++;
					dfs(i,j);
				}
			}
		}
		cout << r<<"\n";
	}
