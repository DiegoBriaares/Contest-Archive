#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll x;
int n,q;
ll v[MAX];
int bs(int in,int fin){
	int mid=(in+fin)/2;
	if(in>=fin)return in;
	if(v[mid]>x)return bs(in,mid-1);
	return bs(mid+1,fin);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
			if(i)v[i]+=v[i-1];
		}
		cin>>q;
		while(q--){
			cin>>x;
			int r=bs(0,n-1);
			if(v[r]<x&&(v[r+1]>=x))r++;
			while(r&&(v[r-1]>=x))r--;
			if(v[r]<x)cout << "-1\n";		
			else cout <<r+1<<"\n";
		}
	}
