#include <bits/stdc++.h>
using namespace std;
#define MAX 90002
char v[MAX];
int n;
string r;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		int i,j,k=n,g,h;
		r.clear();
		for(i=1;i<=n;i++)cin>>v[i];
		for(i=1;i<=n;){
			if(v[i]<v[n])r.push_back(v[i++]);
			else if(v[i]>v[n])r.push_back(v[n--]);
			else {
				for(j=i,g=n;v[j]==v[g]&&g!=j;){
					j++;
					g--;
				}
				if(v[j]<v[g]||g==i){
					r.push_back(v[i]);
					i++;
				}
				else {
					r.push_back(v[n]);
					n--;
				}
			}
		}
		for(int i=0;i<k;i++){
			cout <<r[i];
			if(i%80==0&&i>0)cout<<"\n";
		}
	}
