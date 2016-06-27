#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int n,k;
int v[MAX];
bool cmp(int x){
	int r=0;
	for(int i=0;i<n;i++){
		r+=(v[i]/x);
		if(r>=k)return true;
	}
	return false;
}
int bs(int in,int fin){
	if(in==fin){
		return in;
	}
	int mid=(in+fin)/2;
	if(cmp(mid))return bs(mid+1,fin);
	else return bs(in,mid);
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
		cout << bs(0,MAX)-1<<"\n";
	}
