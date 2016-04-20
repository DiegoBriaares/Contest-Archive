#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
bool v[MAX][MAX];
int n,m;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int i,j,k=0,g,h,r=0,k2=0;
		cin>>m>>n;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++){
				cin>>v[i][j];
				if(v[i][j]){
					if(!k){
						h=j;
						k++;
					}
					else if(k==1){
						g=i;
						k++;
					}
				}
			}
			k=k2=0;
			int uso=0,uso2=0;
			for(i=j=g;i>=1&&j<=n;i--,j++){
				if(v[j][h])uso=1;
				if(v[i][h])uso2=1;
				if(uso&&uso2)break;
				if(!uso)k++;
				if(!uso2)k2++;
			}
			r=max(k,k2);
			k=k2=uso=uso2=0;
			for(i=j=h;i>=1&&j<=m;i--,j++){
				if(v[g][i])uso=1;
				if(v[g][j])uso2=1;
				if(uso&&uso2)break;
				if(!uso)k++;
				if(!uso2)k2++;
			}
			r=max(r,max(k,k2));
			cout << h<<" "<<g<<"\n";
			cout << r<<"\n";
	}
