#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
ll ST[MAX*4];
ll ST2[MAX*4];
ll n,a,b,c,d,s,len;
ll A[MAX],B[MAX];
ll v[MAX];
void buildA(int in,int fin,int nodo){
	if(in==fin){
		ST[nodo]=A[in];
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	buildA(in,mid,left);
	buildA(mid+1,fin,right);
	ST[nodo]=min(ST[left],ST[right]);
}
void buildB(int in,int fin,int nodo){
	if(in==fin){
		ST2[nodo]=B[in];
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	buildB(in,mid,left);
	buildB(mid+1,fin,right);
	ST2[nodo]=min(ST2[left],ST2[right]);
}

ll queryA(int in,int fin,int nodo,int l,int r){
	if(l>fin||r<in)return (1LL<<50);
	if(l<=in&&fin<=r)return ST[nodo];
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	return min(queryA(in,mid,left,l,r),queryA(mid+1,fin,right,l,r));
}
ll queryB(int in,int fin,int nodo,int l,int r){
	if(l>fin||r<in)return (1LL<<50);
	if(l<=in&&fin<=r)return ST2[nodo];
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	return min(queryB(in,mid,left,l,r),queryB(mid+1,fin,right,l,r));
}
ll solve(ll t){
	if(t<0)return (1LL<<50);
	int pos=lower_bound(v, v+n, t) - v;
	if(pos>0&&s+queryA(0,n-1,0,0,pos-1)<0)return (1LL<<50);
	int idx=lower_bound(v, v+n, t+len) - v;
	idx--;
	if(pos<=idx&&s+A[pos-1]+queryB(0,n-1,0,pos,idx)-(pos?B[pos-1]:0)<0)return (1LL<<50);
	return t;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>a>>b>>c>>d>>s>>len;
		for(int i=0;i<n;i++){
			int x;
			cin>>v[i]>>x;
			if(x){
				if(i)A[i]=A[i-1];
				A[i]+=a;
				if(i)B[i]=B[i-1];
				B[i]+=c;
			}
			else {
				if(i)A[i]=A[i-1];
				A[i]-=b;
				if(i)B[i]=B[i-1];
				B[i]-=d;
			}
		}
		buildA(0,n-1,0);
		buildB(0,n-1,0);
		ll res=(1LL<<50);
		res=min(res,solve(0));
		res=min(res,solve(1));
		for(int i=0;i<n;i++){
			res=min(res,solve(v[i]));
			res=min(res,solve(v[i]-len));
			res=min(res,solve(v[i]-len+1));
			res=min(res,solve(v[i]+1));
		}
		if(res!=(1LL<<50))cout << res<<"\n";
		else cout << "-1\n";
	}
