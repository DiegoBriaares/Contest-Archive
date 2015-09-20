#include <bits/stdc++.h>
using namespace std;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		long long n,n1,n5,n10,i,j,k,r=0;
		cin>>n>>n1>>n5>>n10;
		while(n>0){
			if(n10>0){
				n--;
				n10--;
				n1+=2;
				r++;
			}
			if(n5>0){
				if(n5==1&&n1>=3){
					n5--;
					n1-=3;
					r+=4;
					n--;
				}
				else {
					n5-=2;
					n1+=2;
					r+=2;
					n--;
				}
			}
			if(n1>=8){
				n1-=8;
				r+=8;
				n--;
			}
			else break;
		}
		if(n==0)cout << r <<"\n";
		else cout << -1;
	}
