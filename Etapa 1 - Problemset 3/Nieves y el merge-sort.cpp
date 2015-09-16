#include <bits/stdc++.h>
 #define MAXN 100002
using namespace std;

int n,in,fi,co[MAXN],pi[MAXN],v[MAXN],i;
void merge(int i, int j){
	if(i==j)
		return;
	int mitad=(i+j)/2, m=(j-i+1)/2;
	merge(i, mitad);
	merge(mitad+1, j);
	fi=0; in=1;
	for(int p=i; p<=mitad; p++){
		co[++fi]=v[p];
		pi[fi]=v[p+m];
	}
	int pos=i;
	while(fi>0 || in<=m){
		if(fi==0){
			v[pos++]=co[in++];
			continue;
		}
		if(in>m){
			v[pos++]=pi[fi--];
			continue;
		}
		if(pi[fi] < co[in]){
			v[pos++]=pi[fi--];
			continue;
		}
		v[pos++]=co[in++];
	}
}
 
int main() {
	int c;
	cin>>n,c=1;
	for(i=1; i<=n; i++)
		cin>>v[i];
	merge(c,n);
	for(i=1; i<n; i++)
		cout << v[i] << " ";
	cout << v[n] << "\n";
}
