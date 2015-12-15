#include <bits/stdc++.h>
using namespace std;
#define MAX 262144
int A[MAX];
int ST[MAX];
int tamn;
int tamst;
void build(int lo,int hi,int n){
	if(lo==hi){
		ST[n]=A[lo];
		return;
	}
	int mid=(lo+hi)/2;
	int left=n*2+1;
	int right=n*2+2;
	build(lo,mid,left);
	build(mid+1,hi,right);
	ST[n]=min(ST[left],ST[right]);
}
int query(int qlo,int qhi,int lo,int hi,int n){
	if(qlo<=lo&&qhi>=hi){
		return ST[n];
	}
	if(qlo>hi||qhi<lo)
		return 1<<30; //el return es infinito
	int mid=(lo+hi)/2;
	int left=n*2+1;
	int right=n*2+2;
	return min(query(qlo,qhi,lo,mid,left),query(qlo,qhi,mid+1,hi,right));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		for(int rep=1;rep<=t;rep++){
			int n,q,j,g,h,k;
			cin>>tamn>>q;
			for(k=1;k<tamn;k*=2);
			for(int i=0;i<tamn;i++){
				cin>>A[i];
			}
			if(k-tamn>0)for(int i=tamn;i<k;i++)A[i]=1<<30;
			build(0,tamn-1,0);
			cout << "Scenario #"<<rep<<":\n";
			for(int i=0;i<q;i++){
				cin>>g>>h;
				g--;
				h--;
				cout <<query(g,h,0,tamn-1,0)<<"\n";
			}
		}
	}
