#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
long long v[MAX][2],n;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		long long i,j,k=0;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>v[i][0]>>v[i][1];
		}
		for(i=0;i<n;i++){
			if(i==0||i==n-1)k++;
			else {
				if(v[i][0]-v[i][1]>v[i-1][0])k++;
			else if(v[i][0]+v[i][1]<v[i+1][0]){
				v[i][0]+=v[i][1];
				k++;
			}
			}
		}
		cout << k<<"\n";
	}
