#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
pair<int,int>v[MAX];
int n,uso=0,m[MAX];
int bs(int in,int fin,int x){
	if(in==fin)return in;
	int mid=(in+fin)/2;
	if(m[mid]<x)return bs(in,mid,x);
	else return bs(mid+1,fin,x);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int i,j,k,g,h;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>v[i].first>>v[i].second;
		}
		sort(v+1,v+n+1);
		for(i=1;i<=n;i++){
			if(m[uso]>v[i].second||!uso)m[++uso]=v[i].second;
			else {
				k=bs(1,uso,v[i].second);
				if(m[k]>=v[i].second){
					k++;
					uso++;
				}
				m[k]=v[i].second;
			}
		}
		cout << uso<<"\n";
	}
