#include <bits/stdc++.h>
using namespace std;
#define MAX 2002
int n,m;
int a,b;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		for(int i=1;i<MAX;i++){
			for(int j=1;j<MAX;j++){
				if(i*j==n+m&&(((i*2)+(j*2))-4)==n){
					a=i;
					b=j;
					if(a<b)swap(a,b);
					cout << a<<" "<<b<<"\n";
					return 0;
				}
			}
		}
	}
