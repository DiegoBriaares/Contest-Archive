#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
long long n,v[MAX],in=0;
pair<long long,long long>arr[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		long long i,j,r=0;
		cin>>n;
		for(i=0;i<n;i++)cin>>v[i];
		arr[0].first=0;
		arr[0].second=v[0];
		for(i=1;i<=n;i++){
			if(v[i]>=arr[in].second){
				in++;
				arr[in].first=i;
				arr[in].second=v[i];
			}
			else {
				while(in>=0&&arr[in].second>=v[i]){
					r=max(r,((i-arr[in].first)*arr[in].second));
					in--;
				}
				arr[++in].second=v[i];
			}
		}
		cout << r<"\n";
	}
