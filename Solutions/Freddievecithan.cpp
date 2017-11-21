#include <bits/stdc++.h>
using namespace std;
#define MAX 2000002
char v[MAX];
int n;
bool isit(int in,int fin,int in2,int fin2){
	while(v[in]==v[in2]){
		if(in==fin)return true;
		in++;
		in2++;
	}
	return false;
}
bool isita(int in,int fin,int in2,int fin2){
	int uso=0;
	while(1){
		if(v[in]==v[in2])in++,in2++;
		else if(!uso)in++,uso=1;
		else break;
	}
	if(--in==fin&&--in2==fin2)return true;
	else return false;
}
bool isitb(int in,int fin,int in2,int fin2){
	int uso=0;
	while(1){
		if(v[in]==v[in2])in++,in2++;
		else if(!uso)in2++,uso=1;
		else break;
	}
	if(--in==fin&&--in2==fin2)return true;
	else return false;
}
void solve(){
	int mid=(n+1)/2,in=1,fin=mid-1;
	bool a,b,c,d,e;
	a=isit(1,mid-1,mid,n-1);
	b=isit(2,mid,mid+1,n);
	if(a&&b){
		for(int i=1;i<n;i++){
			if(v[i]!=v[i+1]){
				cout <<"NOT UNIQUE\n";
				return;
			}
		}
		for(int j=1;j<mid;j++)cout <<v[j];
		return;
	}
	c=isita(1,mid,mid+1,n); //Esta en la primera mitad.
	d=isitb(1,mid-1,mid,n); //Esta en la segunda mitad.
	e=isit(1,mid-1,mid+1,n); //Esta en la mitad.
	//cout <<"USO: "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<"\n";
	if(!a&&!b&&!c&&!d&&!e){
		cout <<"NOT POSSIBLE\n";
		return;
	}
	if(b)in=2,fin=mid;
	if(c)in=mid+1,fin=n;
	while(in<=fin)cout <<v[in++];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++)cin>>v[i];
		if(!(n&1)){
			cout <<"NOT POSSIBLE\n";
			return 0;
		}
		solve();
	}
