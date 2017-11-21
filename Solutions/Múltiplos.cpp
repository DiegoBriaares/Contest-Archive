#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
#define ll long long
ll r;
int n;
ll a,b;
ll v[MAX];
bool h[1000002];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		cin>>a>>b;
		for(int i=0;i<n;i++){
			for(ll j=(a+((v[i]-(a%v[i]))%v[i]));j<=b;j+=v[i]){
				if(!h[(j-a)])h[(j-a)]=true,r++;
			}
		}
		cout << r<<"\n";
	}
