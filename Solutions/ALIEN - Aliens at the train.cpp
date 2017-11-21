#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		for(cin>>t;t--;){
			long long n,m,i,j,k=0,r1,r2,max1=0,max2=0;
			cin>>n>>m;
			memset(v,0,n+1);
			for(i=0;i<n;i++)cin>>v[i];
			r1=v[0];
			r2=1;
			for(i=1;i<n;i++){
				r1+=v[i];
				r2++;
				while(r1>m){
					r1-=v[k];
					r2--;
					k++;
				}
				if(r2==max2){
					if(r1<max1)max1=r1;
				}
				if(r2>max2){
					max2=r2;
					max1=r1;
				}
			}
			cout << max1 <<" "<<max2<<"\n";
		}
	}
