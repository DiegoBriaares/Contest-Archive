#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX 1000002
long long v[2][MAX],n;
int solve() {
	v[0][0]=1;
   for(int i=1;i<n;i++){ 
   v[0][i]=(v[0][i-1]+v[1][i-1])%MOD; 
   v[1][i]=v[0][i-1];
   }
   return (v[0][n-1]+(v[1][n-1]*2)%MOD)%MOD;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>n;
  	cout << solve()<<"\n";
}
