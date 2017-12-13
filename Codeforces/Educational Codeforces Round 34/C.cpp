#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define MOD 1000000007
#define ll long long
ll n,k,r;
ll v[MAX];
bool memo[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v,v+n);
		for(int i=0;i<n;i++){
			
				for(int j=i+1;j<n;j++){
					if(v[i]<v[j]&&!memo[j]){
						r++;
						memo[j]=true;
						break;
					}
				}
			
		}
		
		cout << n-r<<"\n";
	}
