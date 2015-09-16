#include <bits/stdc++.h>
using namespace std;
#define op ios_base::sync_with_stdio(0);cin.tie(0);
int solve (int n,string v){
	int i,j,h,k=v.size()/n,r=1,s;
	char m;
		for(i=0;i<n;i++){
			for(j=s=0,h=i;j<k;j++,h+=n){
				m=v[h];
					if(m<=90&&m>=65){
					m-=64;
				}
				else if(m>=97&&m<=122){
					m-=96;
				}
				s+=m;
			}
			s=(s%10)+1;
			r*=(s%10);
		}
		r%=10;
		return r+1;
}
	int main (){
		op
		string b,v,v2;
		int n,n2,r,r2;
		char m;
		cin>>b>>n>>v>>b>>n2>>v2;
		r=solve(n,v);
		r2=solve(n2,v2);
		m=r2+64;
		cout << r << "-" << m;
	}
