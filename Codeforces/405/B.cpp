#include <bits/stdc++.h>
using namespace std;
#define MAX 150000
int size[MAX], id[MAX];
long long padres[MAX];
void quick_union_pesado(int N, int M){
	int p, q, j, k;
	for (int i=0; i<N; i++){
		id[i]=i;
		size[i]=1;
	} 
	for (int i=0; i<M; i++){
		cin>>p>>q;
		for (j=p-1; j!=id[j]; j=id[j]);
		for (k=q-1; k!=id[k]; k=id[k]);
		if (j==k){
			padres[j]--;
			continue;
		}
		if (size[j]>size[k]){
			padres[j]+=(long long)size[j]*((long long)size[k])+(long long)padres[k]-1;
			padres[k]=0;
			id[k]=id[j];
			size[j]+=size[k];
		}
		else {
			padres[k]+=(long long)size[j]*((long long)size[k])+(long long)padres[j]-1;
			padres[j]=0;
			id[j]=id[k];
			size[k]+=size[j];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m, bandera=0;
	cin>>n>>m;
	quick_union_pesado(n,m);
	for (int i=0; i<n; i++){
		if (padres[i]>0){
			bandera++;
			break;
		}
	}
	if (bandera==0) cout<<"YES";
	else cout<<"NO";
}
