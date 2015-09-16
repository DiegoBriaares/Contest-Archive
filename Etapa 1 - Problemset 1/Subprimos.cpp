#include <bits/stdc++.h>
using namespace std;
	long primo(long n){
		long c=0,i;
		i=sqrt(n);
		while(i>1){
			if(n%i==0){
				c++;
			}
			i--;
		}
		if(c==0 && n!=1){
			i=1;
		}
		else {
			i=0;
		}
		return i;
	} 
	long pro (long n){
		long f=2,i,uso,uso2,r,c=0;
		while(f<=n){
			while(n%f==0){
				c++;
				n/=f;
			}
			if(f==2){
				f++;
			}
			else {
				f+=2;
			}
		}
		return c;	
	} 
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		long a,b,r,uso,i,c=0;
		cin >>a>>b;
		i=a;
		while(i<=b){
			uso=pro(i);
			r=primo(uso);
			if(r==1){
				c++;
			}
			i++;
		}
		cout << c << "";	
	}
