#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
long long v[MAX],n,q,k;
int bs(){
	int in=1,fin=n,mid;
	mid=(in+fin+1)/2;
	while(in<=fin){
		if(v[mid]<=k)in=mid+1;
		else fin=mid-1;
		mid=(in+fin+1)/2;
	}
	return fin;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int i,j,g;
		cin>>q>>n;
		for(i=1;i<=n;i++){
			cin>>k;
			v[i]=(v[i-1]+k);
		}
		for(i=0;i<q;i++){
			cin>>k;
			j=bs();
			cout << j<<" "<< k-v[j]<<"\n";
		}
	}
