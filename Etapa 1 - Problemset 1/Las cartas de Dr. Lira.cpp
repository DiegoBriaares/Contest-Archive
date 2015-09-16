#include <bits/stdc++.h>
using namespace std;
	int main (){
		int n,c=0,i,r=0,r2=0;
		cin>>n;
		string v;
		cin>>v;
		for(i=0,c=0;i<n;i++,c++){
			if(c%2==0&&v[i]=='B'){
				r++;
			}
			else if(c%2!=0&&v[i]=='W'){
				r++;
			}
		}
		for(i=0,c=1;i<n;i++,c++){
			if(c%2==0&&v[i]=='B'){
				r2++;
			}
			else if(c%2!=0&&v[i]=='W'){
				r2++;
			}
		}
		cout << min(r,r2) << "";
	}
