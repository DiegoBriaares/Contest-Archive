#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MAXK 21
int r;
int n;
int v[MAX];
int memo[MAX][MAXK][3];
int gana(int p1,int p2){
	if(p1==1&&p2==2)return 1;
	else if(p1==2&&p2==3)return 1;
	else if(p1==3&&p2==1)return 1;
	else return 0;
}
int dp(int i,int k,int f){
	if(i==n)return 0;
	if(memo[i][k][f])return memo[i][k][f];
	memo[i][k][f]=dp(i+1,k,f)+gana(f,v[i]);
	if(k==0)return memo[i][k][f];
	for(int j=1;j<=3;j++){
		if(j==f)continue;
		memo[i][k][f]=max(memo[i][k][f],dp(i+1,k-1,j)+gana(j,v[i]));
	}
	return memo[i][k][f];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		freopen("hps.in", "r", stdin);
  		freopen("hps.out", "w", stdout);
		int k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			char aux;
			cin>>aux;
			if(aux=='P')v[i]=3;
			if(aux=='H')v[i]=1;
			if(aux=='S')v[i]=2;
		}
		//Sea 1 = Hoof, 2 = Tijeras, 3 = Papel.
		for(int i=1;i<=3;i++){
			r=max(r,dp(1,k,i)+gana(i,v[0]));
		}
		cout << r<<"\n";
	}
