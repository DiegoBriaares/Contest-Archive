#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll res;
ll n,s;
int v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
			s+=v[i];
		}
		res=400;
		for(int i=0;i<n;i++){
			int sum=0;
			for(int j=0;j<n;j++){
				sum+=(v[(i+j)%n]);
				res=min(res,abs(sum-(s-sum)));
			}
		}	
		cout << res<<"\n";
	}
