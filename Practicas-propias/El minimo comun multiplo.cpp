#include <bits/stdc++.h>
using namespace std;
int v[5];
int n;
bool clean(){
	for(int i=0;i<n;i++)if(v[i]!=1)return false;
	return true;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int i=0,r=1,k=2,j;
		while(cin>>v[i]){
			i++;
		}
		n=i;
		while(!clean()){
			for(i=j=0;i<n;i++){
				if(v[i]%k==0){
					v[i]/=k;
					j++;
				}
			}
			if(!j&&k==2)k++;
			else if(!j&&k>2)k+=2;
			else if(j)r*=k;
		}
		cout << r<<"\n";
	}
