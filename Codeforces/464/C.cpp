#include <bits/stdc++.h>
using namespace std;
#define MAX 301002
#define ll long long
#define MOD 1000000007
ll n,k;
ll s,f;
ll sum;
ll res,sol;
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		cin>>s>>f;
		s--,f--;
		k=(f-s);
		for(int i=0;i<k;i++){
			sum+=v[i];		
		}
		res=sum;
		sol=s-1;
		for(int i=k;i<n;i++){
			sum-=v[i-k];
			sum+=v[i];
			if(sum>res){
				res=sum;
				if((i-k)+1<s){
					sol=(s-((i-k)+1));
				}
				else {
					sol=((n)-((i-k)+1))+(s);
				}
			}
			if(sum==res){
				res=sum;
				ll aux;
				if((i-k)+1<s){
					aux=(s-((i-k)+1));
				}
				else {
					aux=((n)-((i-k)+1))+(s);
				}
				sol=min(sol,aux);
			}
		}
		for(int i=0;i<k;i++){
			sum-=v[(i+n-k)%n];
			sum+=v[i];
			if(sum>res){
				res=sum;
				if(((i+n-k)%n)+1<s){
					sol=(s-(((i+n-k)%n)+1));
				}
				else {
					sol=(n)-(((i+n-k)%n)+1)+(s);
				}
			}
			if(sum==res){
				ll aux;
				if(((i+n-k)%n)+1<s){
					aux=(s-(((i+n-k)%n)+1));
				}
				else {
					aux=(n)-(((i+n-k)%n)+1)+(s);
				}
				sol=min(sol,aux);
			}
		}
		if(sol==n)sol=1;
		else sol++;
		if(sol==0)sol=1;
		cout <<sol<<"\n";
	}
