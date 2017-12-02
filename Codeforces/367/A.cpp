#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n;
ll v[MAX];
double a,b,x,y,t;
double solve(){
	double x_1=(abs(a-x)*abs(a-x));
	double y_1=(abs(b-y)*abs(b-y));
	return sqrt(x_1+y_1);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>a>>b;
		cin>>n;
		double res=100000002;
		for(int i=0;i<n;i++){
			cin>>x>>y>>t;
			double dist=solve();	
			res=min(res,(dist/t));
		}
		cout <<setprecision(7)<<fixed<< res<<"\n";       
	}
