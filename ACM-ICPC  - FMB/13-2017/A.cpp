#include <bits/stdc++.h>
using namespace std;
#define MAX 1005

int N,v[MAX];

int main(){
	int a;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin>>N){
		for (int i=0; i<N; i++) cin>>v[i];
		a=v[N-1]-v[N-2];
		for (int i=N-1; i-1>=0; i--){
			if (v[i]-v[i-1]!=a) {
				cout<<i+1<<"\n";
				break;
			}
			if (i-1==0) cout<<1<<"\n";
		}
		if (N==1) cout<<1<<"\n";
	}
}
