#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll T,A,B,C,D,E;

int main () {
	int s;
	
  	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	cout.tie(0);
  
  	while(cin>>T){
  		s=0;
  		cin>>A;
  		if (A==T) s++;
  		cin>>B;
  		if (B==T) s++;
  		cin>>C;
  		if (C==T) s++;
  		cin>>D;
  		if (D==T) s++;
  		cin>>E;
  		if (E==T) s++;
  		cout<<s<<'\n';
  	}
}
