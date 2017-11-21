#include <bits/stdc++.h>
using namespace std;
#define MAX 34
#define ll long long
int n;
ll x,r;
ll v[MAX];
int p1,p2;
ll permA[6000002];
ll permB[6000002];
int bs(int in,int fin){
	int mid=(in+fin)/2+1;
	if(in==fin)return in;
	if(x+permB[mid]>0)return bs(in,mid-1);
	else return bs(mid,fin);
}
void dfsA(int i,ll s,int c,int k){
	if(i>(n/2)){
		if(c==k){
			permA[++p1]=s;
		}
		return;
	}
	dfsA(i+1,s-v[i],c,k);
	dfsA(i+1,s+v[i],c+1,k);
}
void dfsB(int i,ll s,int c,int k){
	if(i>(n)){
		if(c==k){
			permB[++p2]=s;
		}
		return;
	}
	dfsB(i+1,s-v[i],c,k);
	dfsB(i+1,s+v[i],c+1,k);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		r=-1;
		for(int i=0;i<=(n/2);i++){
			p1=p2=0;
			dfsA(1,0,0,i);
			dfsB((n/2)+1,0,0,(n/2)-i);
			sort(permA+1,permA+p1+1);
			sort(permB+1,permB+p2+1);
			for(int j=1;j<=p1;j++){
				x=permA[j];
				int pos=bs(1,p2);
				if(pos<p2&&abs(x+permB[pos+1])<abs(x+permB[pos]))pos++;
				ll k=abs(x+permB[pos]);
				if(k<r||r==-1)r=k;
			}
		}
		cout << r<<"\n";
	}
