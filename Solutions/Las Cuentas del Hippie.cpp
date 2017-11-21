#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int v[MAX],n,k,r=MAX;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int i,j,g,h,ne=0,b=0;
		cin>>k>>n;
		for(i=0;i<n;i++){
			cin>>v[i];
			v[i+n]=v[i];
		}
		for(i=j=0;i<(n*2);){
			if(v[i]==0&&ne<k){
				ne++;
				i++;
			}
			else if(v[i]==1&&ne<k){
				b++;
				i++;
			}
			if(ne==k){
				if(b<r)r=b;
				if(v[j]==0){
					ne--;
				}
				else b--;
				j++;
			}
		}
		cout << r<<"\n";
	}
