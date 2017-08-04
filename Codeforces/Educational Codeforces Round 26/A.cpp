#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
#define ll long long
string n;
int r,aux;
string v;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		getline(cin,n);
		getline(cin,v);
		for(int i=0;i<v.size();i++){
		//	cout << "AUX: "<<v[i]<<" "<<r<<" "<<aux<<"\n";
			if(v[i]==' '){
				r=max(r,aux);
				aux=0;
			}
			else {
				if(v[i]>='A'&&v[i]<='Z')aux++;
			}
		}
		r=max(r,aux);
		cout << r<<"\n";
	}
