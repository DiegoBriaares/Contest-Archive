#include <bits/stdc++.h>
using namespace std;
#define MAX

int N,L[20],s=0,k;

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	L[0]=32;
	L[1]=16;
	L[2]=8;
	L[4]=4;
	L[8]=2;
	L[16]=1;
	cin>>N;
	for (int i=0; i<N; i++){
		cin>>k;
		s+=L[k];
	}
	cout<<setprecision(7)<<fixed<<((double)s)/((double)16)<<"\n";
	return 0;
}
