#include <bits/stdc++.h>
using namespace std;
#define MAX 64
#define ll long long
ll n;
ll pot[MAX];
	int main (){
		ios_base::sync_with_stdio();
		cin.tie(0);
		cin>>n;
		pot[0]=1;
		for(int i=1;i<MAX;i++){
			pot[i]=2*pot[i-1];
		}
		for(int i=1;i<MAX;i++){
			pot[i]+=pot[i-1];
		}
		for(int i=0;i<n;i++){
			if(pot[i]>=n){
				cout << (((n-pot[i-1]))%10)<<" "<<((n-pot[i-1]))<<"\n";
				return 0;
			}
		}
	}
