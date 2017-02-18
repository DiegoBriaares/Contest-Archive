#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll res=(1<<30);
ll r;
int n;
int idx;
ll s,f,t;
ll v[MAX];
stack<ll>pila;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>s>>f>>t;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		if(v[0]<=s&&v[0]){
			r=v[0]-1;
			res=s-r;
			++res;
		}
		if(s+(t*((n+1)))<=f)r=v[n-1]+t;
		for(int i=1;i<n;i++){
			if(abs(v[i]-v[i-1])>1){
				if(v[i]<s){
					if((s+(t*i))-(v[i]-1)>=f)continue;
					if((s+(t*i))-(v[i]-1)+(s-(v[i]-1))+1<=res){
						r=v[i]-1;
						res=(s+(t*i))-(v[i]-1);
					}
				}
				else if(v[i]!=s&&(v[i]-1)+t<=f){
					r=v[i]-1;
				}
			}
		}
		cout << r<<"\n";
	}
