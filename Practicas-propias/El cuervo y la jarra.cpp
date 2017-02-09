#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int n,q;
int x,y;
int v[MAX];
int bs(int in,int fin){
	int mid=(in+fin)/2;
	if(v[mid]-v[y]==x)return mid;
	if(in==fin&&mid>0&&v[mid-1]-v[y]>=x)return mid-1;
	else if(in==fin)return in;
	if(v[mid]-v[y]>x)return bs(in,mid);
	else return bs(mid+1,fin);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(!i)v[i]=x;
			else v[i]=v[i-1]+x;
		}
		cin>>q;
		while(q--){
			y--;
			cin>>x>>y;	
			int r=bs(y,n);		
			cout << (v[r]-v[y]>=x?r-1:n)<<"\n";
		}
	}
