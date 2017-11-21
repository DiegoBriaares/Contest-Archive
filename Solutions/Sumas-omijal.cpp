#include <bits/stdc++.h>
using namespace std;
#define MAX 12
int v[MAX],arr[MAX];
int n,k;
void copy(){
	for(int i=0;i<n;i++)arr[i]=v[i];
}
bool solve(){
	copy();
	for(int i=1;i<=(n-1);i++){
		for(int j=0;j<(n-i);j++){
			arr[j]+=arr[j+1];
		}
	}
	if(arr[0]==k)return true;
	else return false;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=0;i<n;i++)v[i]=i+1;
		do {
			if(solve()){
				for(int i=0;i<n;i++)cout <<v[i]<<" ";
				return 0;	
			}
		}while(next_permutation(v,v+n));
	}
