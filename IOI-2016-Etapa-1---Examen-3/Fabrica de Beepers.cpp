#include <bits/stdc++.h>
using namespace std;
#define MAX 22
int v[MAX];
bool ok(){
	for(int i=0;i<MAX;i++){
		if(v[i]!=0)return false;
	}
	return true;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n,i,j,k,g,h,uso=0,r=0,uso2=1,uso3=2;
		cin>>n;
		memset(v,0,sizeof(v));
		for(i=0;i<n;i++)cin>>v[i];
		sort(v,v+n);
		reverse(v,v+n);
		while(!ok()){
			for(i=uso,g=uso2,h=uso3,j=0;j<3;j++,i++,g++,h++){
				if(v[uso]!=0&&j==0){
					v[uso]-=9;
					if(v[uso]<1)v[uso]=0,uso+=3;
				}
				if(v[uso2]!=0&&j==1){
					v[uso2]-=3;
					if(v[uso2]<1)v[uso2]=0,uso2+=3;
				}
				if(v[uso3]!=0&&j==2){
					v[uso3]-=1;
					if(v[uso3]<1)v[uso3]=0,uso3+=3;
				}
			}
			r++;
		}
		cout << r<<"\n";
	}
	
