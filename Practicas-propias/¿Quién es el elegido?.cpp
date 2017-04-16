#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll cicles;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		if(k<=n){
			cout <<k<<"\n";
			return 0;
		}
		k-=n;
		n--;
		cicles=(k/n);
		if(cicles%2!=0){  //Va pa la derecha.
			cout << (k%n)+1<<"\n";
		}
		else {
			//cout << "pass\n";
			cout << ((n+1)-(k%n))<<"\n";
		}
	}
