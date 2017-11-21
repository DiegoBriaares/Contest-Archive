#include <bits/stdc++.h>
using namespace std;
#define MAX 102
int m[MAX][MAX],n,c;
	int main (){
		
		cin>>n>>c;
		int a=1,b=1,i,j,k=1,r=n*c,uso=n,uso2=c;
		while(k<=(r)){
			for(i=b;i<=c;i++){
				m[a][i]=k++;
			}
			for(i=a+1;i<=n;i++){
				m[i][c]=k++;
			}
			for(i=c-1;i>=b;i--){
				m[n][i]=k++;
			}
			for(i=n-1;i>a;i--){
				m[i][b]=k++;
			}
			a++;
			n--;
			b++;
			c--;
		}
		for(i=1;i<=uso;i++){
			for(j=1;j<=uso2;j++){
				cout << m[i][j]<<" ";
			}
			cout <<"\n";
		}
	}
