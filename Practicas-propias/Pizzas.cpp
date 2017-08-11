#include <bits/stdc++.h>
using namespace std;
int r;
int a,b,c;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>a>>b>>c;
		while(a&&c){
			r++;
			a--,c--;
		}
		if(c){
			while(c)r++,c--;
		}
		if(b%2==0){
			r+=(b/2);
			r+=(a/4);
			if(a%4!=0){
				r++;
			}
		}
		else {
			r+=(b/2);
			r++;
			a-=2;
			if(a<0)a=0;
			r+=(a/4);
			if(a%4!=0){
				r++;
			}
		}
		cout << r<<"\n";
	}
