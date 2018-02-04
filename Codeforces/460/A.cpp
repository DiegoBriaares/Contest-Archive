#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 9999999999999
ll n;
ll v[MAX];
double res,k;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		res=INF;
		for(int i=0;i<n;i++){
			double a,b;
			cin>>a>>b;
			res=min(res,(a/b));
		}
		cout <<setprecision(7)<<fixed<< (res*k)<<"\n";
	}
