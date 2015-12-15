#include <bits/stdc++.h>
using namespace std;
#define MAX 50000
int v[MAX],ct=0;
void fx(long long n,long long uso){
	long long k=2,i,j,g,h;
	j=n;
	while(k*k<=j){
			while(n%k==0){
				n/=k;
				v[ct]=k;
				ct++;
			}
		if(k==2)k++;
		else k+=2;
	}
	if(n>1){
		v[ct]=n;
		ct++;
	}
}
	int main (){
		
		long long n,c,g,h,k,i,uso=0;
		while(cin>>n>>c){
			uso=0;
			memset(v,0,sizeof(v));
			ct=0;
			if(n==0&&c==1)cout <<c<<" divides "<<n<<"!\n";
		else {
		fx(c,n);
		for(i=0,g=1,h=0,k=v[0];i<ct;i++){
		//	cout <<"R: "<<v[i]<<"\n";
		if(v[i]!=v[i-1]&&i>0) {
					k=v[i];
					g=1;
					h=0;
				}
				if(v[i]==v[i-1]){
					g++;
				}
				h+=(n/pow(k,g));
				if(g>h){
						cout <<c<<" does not divide "<<n<<"!\n";
						uso++;
						break;
					}
			//	cout << "USO: "<<h<<"\n";
				
		}
		if(uso==0)cout <<c<<" divides "<<n<<"!\n";
	}
	}
	}
