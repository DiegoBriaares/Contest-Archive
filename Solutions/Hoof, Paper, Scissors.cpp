#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int n;
int r;
int v[MAX];
int dp[3][MAX];
int gana(int p1,int p2){
	if(p1==1&&p2==2)return 1;
	else if(p1==2&&p2==3)return 1;
	else if(p1==3&&p2==1)return 1;
	else return 0;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		freopen("hps.in", "r", stdin);
  		freopen("hps.out", "w", stdout);
		cin>>n;
		for(int i=0;i<n;i++){
			char aux;
			cin>>aux;
			if(aux=='P')v[i]=3;
			if(aux=='H')v[i]=1;
			if(aux=='S')v[i]=2;
		}
		for(int i=1;i<=3;i++){
			dp[i][0]=gana(i,v[0]);
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=3;j++){
				dp[j][i]=dp[j][i-1]+gana(j,v[i]);
			}
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=3;j++){
				for(int l=1;l<=3;l++){
					r=max(r,(dp[j][i-1]+(dp[l][n-1]-dp[l][i-1])));
				}
			}
		}
		cout << r<<"\n";
	}
