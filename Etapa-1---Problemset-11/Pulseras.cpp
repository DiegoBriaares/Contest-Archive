#include <bits/stdc++.h>
using namespace std;
#define MOD %1000000007
#define MAX 1000009
#define llu unsigned long long 
llu v[MAX],n;
llu solve() {
	v[0]=v[1]=1;
   for(llu i=2;i<n+2;i++){ 
   v[i]=v[i-1]+v[i-2]MOD; 
   }
   return (v[n]+v[n-2])MOD;
}
int main(){ //Esto es Fibonnaci
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>n;
  	cout << solve()<<"\n";
}
