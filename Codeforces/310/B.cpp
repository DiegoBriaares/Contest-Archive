#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n,k;
ll v2[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v2[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j&1){
					v2[j]=(v2[j]+n-1)%n;
				}
				else v2[j]=(v2[j]+1)%n;
			}
			
			if(v2[0]==0){
				bool ok=false;
				for(int j=1;j<n;j++){
					if(v2[j]-v2[j-1]!=1){
						ok=true;
						break;
					}
				}
				if(!ok){
					cout << "Yes\n";
					return 0;
				}
			}
		}
		cout << "No\n";
	}
