#include <bits/stdc++.h>
using namespace std;
int n;
char v[2000002];
bool maybe(int in,int fin,int in2,int fin2){
	while(v[in]==v[in2]){
		in++;
		in2++;
	}
	while(v[fin]==v[fin2]){
		fin--;
		fin2--;
	}
	if(in>fin||in2>fin2)return true;
	return false;
}
void solve(){
	int a,b,c,d,e,m=((n+1)/2),in=1,fi=m-1;
	a=maybe(1,m-1,m,n-1);
	b=maybe(2,m,m+1,n);
	if(a&&b){
		int uso=0;
		for(int i=1;i<n;i++){
			if(v[i]!=v[i+1]){
				cout <<"NOT UNIQUE\n";
				return;
			}
		}
		for(int i=1;i<m;i++)cout <<v[i];
		return;
	}
	c=maybe(1,m,m+1,n);
	d=maybe(1,m-1,m,n);
	e=maybe(1,m-1,m+1,n);
	if(!a&&!b&&!c&&!d&&!e){
		cout <<"NOT POSSIBLE\n";
		return;
	}
	if(a)in=1,fi=m-1;
	if(b)in=2,fi=m;
	if(c)in=m+1,fi=n;
	while(in<=fi){
		cout << v[in];
		in++;
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++)cin>>v[i];
		if(n%2==0){
			cout <<"NOT POSSIBLE\n";
			return 0;
		}
		solve();
	}
