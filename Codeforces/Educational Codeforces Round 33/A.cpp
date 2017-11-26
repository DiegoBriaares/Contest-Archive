#include <bits/stdc++.h>
using namespace std;
#define MAX 300002
#define ll long long
ll n,k;
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		int p1=1,p2=2,p3=3;
		for(int i=0;i<n;i++){
			if(v[i]!=p1&&v[i]!=p2){
				cout << "NO\n";
				return 0;
			}
			if(v[i]==1){
				if(p1==1)swap(p2,p3);
				else if(p2==1)swap(p1,p3);
			}
			else if(v[i]==2){
				if(p1==2)swap(p2,p3);
				else if(p2==2)swap(p1,p3);
			}
			else {
				if(p1==3)swap(p2,p3);
				else if(p2==3)swap(p1,p3);
			}
		}
		cout << "YES\n";
	}
