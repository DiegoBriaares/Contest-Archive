#include <bits/stdc++.h>
using namespace std;
#define MAX 500100
#define MOD 1000000007
long long n,v[2][MAX],s=0,r=0,i,j,k;
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>v[0][i]>>v[1][i];
	}
	for(i=0;i<2;i++){
		sort(v[i],v[i]+n);
		for(j=1;j<n;j++){
			s+=v[i][j];
		}
		j--;
		for(k=0;k<n-1;k++,j--){
		r+=(s-(v[i][k]*j))%MOD;
		r%=MOD;
		s-=v[i][k+1];
	}
	}
	r%=MOD;
	cout << r%MOD<<"\n";
}
