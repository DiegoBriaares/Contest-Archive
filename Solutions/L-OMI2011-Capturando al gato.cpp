#include <bits/stdc++.h>
using namespace std;
#define MAX 5002
#define MAXN 4000002
#define ll long long
ll v[MAX];
ll s[MAX];
ll bucket[MAXN];
ll n;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		int i,j,k,g;
		for(i=1;i<=n;i++){
			cin>>v[i];
			s[i]=v[i]+s[i-1];
		}
		for(i=n;i>=2;i--){
			if(s[n]%i==0){
				k=s[n]/i;
				for(j=1;j<=n;j++){
					bucket[s[j]%k]++;
				}
				for(j=0;j<=k;j++){
					if(bucket[j]==i){
						cout <<i<<"\n";
						return 0;
					}
					bucket[j]=0;
				}
			}
		}
		cout << 0<<"\n";
	}
