#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n,k;
ll r1,r2;
ll v[MAX];
ll DP[MAX];
ll bs(int i){
	int in=0,fin=n,mid,res=0;
	while(in<=fin){
		mid=(in+fin)/2;
		if((i+(mid))-1<n&&((v[i]*mid)-(DP[(i+mid)-1]-(i?DP[i-1]:0)))<=k){
			in=mid+1;
			res=mid;
		}
		else fin=mid-1;
	}
	return res;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v,v+n);
		reverse(v,v+n);
		DP[0]=v[0];
		for(int i=1;i<n;i++){		
			DP[i]=v[i]+DP[i-1];
		}
		for(int i=0;i<n;i++){
			int aux=bs(i);
			if(aux>=r1){
				r1=aux;
				r2=v[i];
			}
		}
		cout << r1<<" "<<r2<<"\n";
	}
