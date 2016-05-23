#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll v[11],v2[11];
ll a[5],b[5];
ll r=0;
int x[5],y[5];
void solve (int in,int fin,int in2,int fin2){
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	int i=0,n=0,n2=0;
		while(in<=fin){
			x[i++]=a[in++];
			n++;
		}
		i=0;
		while(in2<=fin2){
			y[i++]=v[in2++];
			n2++;
		}
			sort(y,y+n2);
			sort(x,x+n);
			reverse(x,x+n);
			ll p=0;
		/*	cout <<"ORD: \n";
			for(int i=0;i<n;i++)cout << x[i]<<" ";
			cout <<"\n";
			for(int i=0;i<n2;i++)cout << y[i]<<" ";
			cout <<"\n";*/
			for(int j=0;j<n;j++){
				p=0;
				for(int i=0;i<n2;i++){
				if(y[i]>=x[j]){
					//cout << x[j]<<"PASA A "<<y[i-1]<<"\n";
					if(i>0)y[i-1]=(1<<30);
					break;
				}
				p++;
				}
			if(!p){
				return;
			}
			r++;
			}
}
void solve2 (int in,int fin,int in2,int fin2){
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	int i=0,n=0,n2=0;
		while(in<=fin){
			x[i++]=b[in++];
			n++;
		}
		i=0;
		while(in2<=fin2){
			y[i++]=v2[in2++];
			n2++;
		}
			sort(y,y+n2);
			sort(x,x+n);
			reverse(x,x+n);
			ll p=0;
		/*	cout <<"ORD: \n";
			for(int i=0;i<n;i++)cout << x[i]<<" ";
			cout <<"\n";
			for(int i=0;i<n2;i++)cout << y[i]<<" ";
			cout <<"\n";*/
			for(int j=0;j<n;j++){
				p=0;
				for(int i=0;i<n2;i++){
				if(y[i]>=x[j]){
					//cout << x[j]<<"PASA A "<<y[i-1]<<"\n";
					if(i>0)y[i-1]=(1<<30);
					break;
				}
				p++;
				}
			if(!p){
				return;
			}
			r++;
			}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		char n;
		cin>>n;
		for(int i=0;i<11;i++)cin>>v[i];
		for(int i=0;i<11;i++)cin>>v2[i];
		for(int i=0;i<5;i++)cin>>a[i];
		for(int i=0;i<5;i++)cin>>b[i];
		if(n=='A'){
			solve(0,1,0,3);
			solve(2,3,4,7);
			solve(4,4,8,10);
			cout <<r<<"\n";
		}
		else if(n=='B'){
			solve2(0,1,0,3);
			solve2(2,3,4,7);
			solve2(4,4,8,10);
			cout <<r<<"\n";
		}
	}
