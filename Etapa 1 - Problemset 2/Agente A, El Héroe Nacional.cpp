#include <bits/stdc++.h>
using namespace std;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		long long int n,t,r,r2,s=0,uso=0,i=0;
		cin >>n>>t;
		long long int v[n],v2[n]; 
		while(i<n){
			cin >>v[i]>>v2[i];
			i++;
		}
		i=0;
		while(i<n){
			r=__gcd(v[i],v2[i]);
			uso=min(v[i],v2[i]);
			uso/=r;
			if(v[i]!=v2[i]){
				uso++;
			}
			s+=uso;
			i++;
		}
		s--;
		if(s<=t)
		cout << s << "";
		else {
			cout << "El Agente A no sera heroe nacional, el Doctor B destruira su pais" << "";
		}
	}
