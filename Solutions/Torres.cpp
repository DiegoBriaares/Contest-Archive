#include <bits/stdc++.h>
using namespace std;
#define MAX 5002
#define ll int
#define INF 999999999
int n;
ll v[MAX];
ll dp[MAX][MAX];
ll suma[MAX],sum[MAX][MAX];
void prec(){
    for(int i=1; i<=n; i++){
        suma[i]=suma[i-1]+v[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            sum[i][j]=suma[j]-suma[i-1]; 
        }    
    }    
}
int bin(int in,int fin,int a,ll s){
    int mid=(in+fin)/2;
    if(in==fin){
    	if(sum[a][in]>=s)return in;
    	return -1;
	}
	if(sum[a][mid]>=s)return bin(in,mid,a,s);
	return bin(mid+1,fin,a,s);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		prec();
		for(int i=n;i>=1;i--){
			ll a,b;
			for(int j=n;j>=i;j--){
				a=b=(INF);
				a=dp[i][j+1]+1;
				if(j==n)a--;
				if(j<n){
					if(sum[j+1][n]>=sum[i][j]){
						int pos=bin(j+1,n,j+1,sum[i][j]);
						if(pos==-1)continue;
						b=dp[j+1][pos]+(pos-(j+1));
					}
				}
				dp[i][j]=min(a,b);
			}
		}
		cout << dp[1][1]<<"\n";
	}
