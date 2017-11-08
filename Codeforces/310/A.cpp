#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n,k;
string v;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		cin>>v;
		int c=0,u=0;
		for(int i=0;i<n;i++){
			if(v[i]=='1')u++;
			else c++;
		}
		int aux=min(u,c);
		cout << (int)(v.size())-2*aux<<"\n";
	}
