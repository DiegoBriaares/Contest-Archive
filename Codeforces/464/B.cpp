#include <bits/stdc++.h>
using namespace std;
#define MAX 301002
#define ll long long
#define MOD 1000000007
ll n,k;
ll a,b,res;
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		res=-1;
		for(int i=1;i<=k;i++){
			cin>>v[i];
			if(n%v[i]<res||res==-1){
				res=n%v[i];
				a=i;
				b=(n/v[i]);
			}
		}
		cout << a<<" "<<b<<"\n";
	}
