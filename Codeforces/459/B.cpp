#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 99999999999999999
ll res;
ll n,k,c;
map<string,string>m;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		for(int i=1;i<=n;i++){
			string a,b;
			cin>>a>>b;
			m[b]=a;
		}
		while(c--){
			string a,b;
			cin>>a>>b;
			string ip="";
			for(int i=0;i<b.size()-1;i++)ip+=b[i];
			cout << a <<" "<<b<<" #"<<m[ip]<<"\n";
		}
		
	}
