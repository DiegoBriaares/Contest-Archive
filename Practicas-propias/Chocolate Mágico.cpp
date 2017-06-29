#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
int n;
double a,b,c;
double v[MAX];
double DP[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>a>>b>>c;
		for(int i=0;i<n;i++){
			cin>>v[i];
			if(i)v[i]+=v[i-1];
		}
		for(int i=0;i<n;i++){
			if(DP[i]||!i){
				DP[i+(int)a]=max(DP[i+(int)a],((v[min(i+(int)a-1,n-1)]-(i?v[i-1]:0))/a)+DP[i]);
				DP[i+(int)b]=max(DP[i+(int)b],((v[min(i+(int)b-1,n-1)]-(i?v[i-1]:0))/b)+DP[i]);
				DP[i+(int)c]=max(DP[i+(int)c],((v[min(i+(int)c-1,n-1)]-(i?v[i-1]:0))/c)+DP[i]);
			}
		}
		if(DP[n]){
			cout <<fixed<< setprecision(2)<<DP[n]<<"\n";
		}
		else cout << "Lo siento amigo\n";
	}
