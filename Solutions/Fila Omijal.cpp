#include <bits/stdc++.h>
using namespace std;
#define MAX 1008
int v[MAX],n,v2[MAX];
void solve(int i,int j){
	int uso=v2[j],k,g,uso2;
	v2[j]=v[i];
	for(g=j+1;g<=i;g++){
		uso2=v2[g];
		v2[g]=uso;
		uso=uso2;
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		int i,j,k,g,r=0,h;
		for(i=0;i<n;i++)cin>>v[i];
		for(i=0;i<n;i++){
			for(j=0;v[i]>v2[j]&&v2[j]>0&&j<=i;j++);
			r+=j;
		//	cout << "R: "<<j<<"\n";
			solve(i,j);
		}
		//for(i=0;i<n;i++)cout << v2[i]<<" ";
		cout << r<<"\n";
	}
