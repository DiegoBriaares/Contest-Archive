#include <bits/stdc++.h>
using namespace std;
#define MAX 1000102
#define ll long long
#define MOD 1000000007
ll n,k;
bool ok;
stack<ll>pila;
vector<ll>v,b;
bool memo[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		v.push_back(0);
		for(int i=1;i<=k;i++){
			int x;
			cin>>x;
			v.push_back(x);
		}
		v[0]=(1<<30);
		ll p=1,idx=k,as=0;
		int uso=0;
		for(int i=1;i<=k;i++){
			pila.push(v[i]);
			b.push_back(v[i]);
			memo[v[i]]=true;
			if(v[i]==p){
				while(!pila.empty()&&pila.top()==p){
					pila.pop();
					uso++;
					memo[p]=true;
					p++;
				}
			}
			if(v[i]>v[i-1]&&v[i-1]>p){
				cout << "-1\n";
				return 0;
			}
		}
		for(int i=k+1;i<=n;){
			while(idx&&v[idx]<=p)idx--;
			if(idx>=1){
				while(i<=n&&v[idx]>p){
					if(!memo[v[idx]]){
						b.push_back(v[idx]);
						i++;
						memo[v[idx]]=true;
					}
					v[idx]--;
				}
				memo[p]=true;
				b.push_back(p++);
				while(p<=n&&memo[p])p++;
				i++;
				while(idx&&v[idx]<=p)idx--;
			}
			else {
				int aux=n;
				while(i<=n&&aux>=p){
					if(!memo[aux]){
						b.push_back(aux);
						i++;
						memo[aux]=true;
					}
					aux--;
				}
			}
		}
		for(int i=0;i<b.size();i++){
			cout << b[i]<<" ";
		}
		cout << "\n";
	}
