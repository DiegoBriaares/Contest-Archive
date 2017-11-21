#include <bits/stdc++.h>
using namespace std;
#define MAX 56
char arr[MAX][MAX];
bool v[MAX][MAX];
int n,m,f,c,e;
bool yes=false;
void dfs(int i,int j){
	if(i>=n||j>=m||i<0||j<0||v[i][j]||arr[i][j]=='.'||yes)return;
	if(i==(f-1)&&j==(c-1)){
		yes=true;
		return;
	}
	v[i][j]=true;
	dfs(i,j+1);
	dfs(i,j-1);
	for(int uso=e;uso>0;uso--){
		dfs(i+uso,j);
		dfs(i-uso,j);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		cin>>f>>c;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		for(e=0;e<n;e++){
			memset(v,false,sizeof(v));
					dfs(n-1,0);
					if(yes){
						cout << e<<"\n";
						return 0;
					}	
		}
	}
