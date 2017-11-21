#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
pair<int,int>v[MAX];
int n,arr[MAX],point=0;
int bs(int in,int fin,int x){
	if(in==fin)return in;
	int mid=(in+fin)/2;
	if(arr[mid]<x)return bs(in,mid,x);
	else return bs(mid+1,fin,x);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i].first>>v[i].second;
		}	
		sort(v,v+n+1);
		for(int i=1;i<=n;i++){
			if(v[i].second<=arr[point]||!point)arr[++point]=v[i].second;
			else {
				int pos=bs(1,point,v[i].second);
				if(arr[pos]>=v[i].second){
					point++;
					pos++;
				}
				arr[pos]=v[i].second;
			}
		}
		cout << point<<"\n";
	}
