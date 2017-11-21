#include <bits/stdc++.h>
using namespace std;
#define MAX 1000100
#define ll long long
ll n;
ll a,b;
ll v[MAX*2];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			ll j;
			cin>>j;
			v[j]++;
		}
		for(int i=MAX;i>=1;i--){   //Esto me da el multiplico en el que voy a ir recorriendo.
			a=b=0;
			for(int j=MAX-(MAX%i);j>0;j-=i){
				if(v[j]&&!a){
					if(v[j]>1){
						a=j;
						b=j;
						break;
					}
					else a=j;
				}
				else if(v[j]&&a&&!b){
					b=j;
					break;
				}
			}
			if(a&&b){
				if(a%b==0)cout <<a<<"\n";
				else cout << ((a*b)/i)<<"\n";
				return 0;
			}
		}
	}
