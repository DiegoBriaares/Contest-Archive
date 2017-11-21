#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define ll long long
int n;
string s;
int tam[MAX];
bool vis[MAX];
vector<string>v;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			string aux;
			cin>>aux;
			if(aux.size()>s.size()){
				s=aux;
			}
			v.push_back(aux);
			tam[i]=aux.size();
		}
		int r=(1<<30);
		for(int i=0;i<s.size();i++){
			int c=0;
			for(int j=0;j<n;j++){
				if(!vis[j]&&v[j][i]==s[i]){
					tam[j]--;
				}	
				else {
					tam[j]++;
					vis[j]=true;
				}
				c=max(c,tam[j]);
			}
			r=min(r,c);
		}
		cout <<r<<"\n";	
	}
