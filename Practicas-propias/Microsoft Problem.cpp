#include <bits/stdc++.h>
using namespace std;
#define MAX 20
int n;
int m[MAX][MAX];
int memo[MAX];
vector<vector<int> >sol;
int v[MAX];
bool checa(){
	for(int i=1;i<n;i++){
		if(!m[v[i]][v[i+1]])return false;
	}
	return true;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				char uso2;
				cin>>uso2;
				if(uso2=='W'){
					m[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			v[i]=i;
		}
		do {
			if(checa()){
				for(int i=1;i<=n;i++){
					cout << v[i]<<" ";
				}
				return 0;
			}
		}while(next_permutation(v+1,v+n+1));
	}
