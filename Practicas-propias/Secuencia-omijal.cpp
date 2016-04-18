#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int v[MAX],n,r[MAX];
bool h[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		int i,j,uso;
		n--;
		for(i=0;i<=n;i++)cin>>v[i];
		for(i=n;i>=0;i--){
			for(j=n,uso=0;j>=0;j--){
				if(uso==v[i]&&!h[j]){
					r[i]=j;
					h[j]=true;
					break;
				}
				if(!h[j])uso++;
			}
		}
		for(i=0;i<=n;i++)cout<<r[i]<<" ";
	}
