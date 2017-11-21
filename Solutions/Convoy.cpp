#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
double n,m,l;
double r;
double memo[MAX];
pair<double,double>v[MAX];
double dp(int i){
	if(i==n)return 0;
	if(memo[i])return memo[i];
	memo[i]=(1<<30);
	double s=0,me=(1<<30);
	for(int j=i;j<n&&s+v[j].first<=m;j++){
		me=min(me,v[j].second);
		s+=v[j].first;
		memo[i]=min(memo[i],dp(j+1)+((l/me)*60));
	}
	return memo[i];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		while(1){
			cin>>m>>l>>n;
			if(m+l+n==0)return 0;
			memset(memo,0,sizeof(memo));
			for(int i=0;i<n;i++){
				cin>>v[i].first>>v[i].second;
			}
			printf("%.1lf\n",dp(0));
		}
	}
