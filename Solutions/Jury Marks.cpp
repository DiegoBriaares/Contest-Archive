#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
int n,k;
ll a[MAX];
ll b[MAX];
set<ll>S,S2;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i)a[i]+=a[i-1];
		}
		for(int i=0;i<k;i++){
			cin>>b[i];
		}
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
				if(S.find(b[i]-a[j])!=S.end()||!i)S2.insert(b[i]-a[j]);
			}
			S=S2;
			S2.clear();
		}
		cout << S.size()<<"\n";
	}
