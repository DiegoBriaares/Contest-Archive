#include <bits/stdc++.h>
using namespace std;
#define MAX 22
int n,v[MAX],da[1<<21],vi[1<<21];
int doit(int i){
	int r=0;
	for(int j=0;j<n;j++){
		if((i&(1<<j))==0)r+=v[j];
	}
	return r;
}
int dp(int ma){
	if((1<<n)-1==ma)return 0;
	if(vi[ma]>0)return vi[ma];
	int mini=1<<30;
	for(int i=0;i<n;i++){
		if((ma&(1<<i))!=0)continue;
		int uso=ma;
		uso|=(1<<i);
		uso|=(1<<((i+1)%n));
		uso|=(1<<((i+n-1)%n));
		mini=(min(mini,dp(uso)+da[uso]));
	}
	return vi[ma]=mini;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int uso;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<=(1<<20);i++){
			da[i]=doit(i);
		}
		cout << dp(0)<<"\n";
	}
