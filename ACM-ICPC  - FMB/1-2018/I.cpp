#include <bits/stdc++.h>
using namespace std;
#define MAX 15

int N,T,H[MAX],m;

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	for (int i=0; i<N; i++){
		cin>>H[i];
	}
	cin>>T;
	m=0;
	for (int i=1; i<N; i++){
		if ((T%(H[i]))<(T%(H[m]))) m=i;
	}
	cout<<H[m]<<"\n";
	return 0;
}
