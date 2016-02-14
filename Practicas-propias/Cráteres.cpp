#include <bits/stdc++.h>
using namespace std;
#define MAX 502
int m[MAX][MAX],n,c,r=0,r2=0,cont=1,uso;
bool v[MAX][MAX];
void dfs(int i,int j){
	if(v[i][j]||i>=n||j>=c||m[i][j]==0||i<0||j<0)return;
	v[i][j]=true;
	uso+=m[i][j];
	dfs(i+1,j);
	dfs(i,j+1);
	dfs(i-1,j);
	dfs(i,j-1);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				cin>>m[i][j];
			}
		}
		for(int j=0;j<c;j++){
			for(int i=0;i<n;i++){
				if(m[i][j]>0&&!v[i][j]){
					uso=0;
					dfs(i,j);
					if(uso>r){
						r=uso;
						r2=cont;
					}
					cont++;
				}
			}
		}
		cout << r2 <<" "<<r<<"\n";
	}
