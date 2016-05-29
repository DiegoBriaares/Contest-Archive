#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,r;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;	
		for(int i=0;i<=(n/3);i++){
			r+=((n-(3*i))/2)+1;
		}
		cout << r<<"\n";
	}
