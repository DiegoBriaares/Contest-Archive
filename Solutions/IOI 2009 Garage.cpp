#include <bits/stdc++.h>
using namespace std;
#define MAX 2002
#define ll long long
ll r;
int us;
int n,m;
ll v[MAX];
ll w[MAX];
int h[MAX];
queue<int>cola;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int rep=0;rep<2*m;rep++){
			int car;
			cin>>car;
			if(car>=0){
				if(us<n){
					for(int i=0;i<n;i++){
						if(!h[i]){
							h[i]=car;
							r+=(w[car]*v[i]);
							break;
						}
					}
					us++;
				}
				else cola.push(car);
			}
			else {
				us--;
				car*=(-1);
				for(int i=0;i<n;i++){
					if(h[i]==car){
						h[i]=0;
						break;
					}
				}
				while(us<n&&!cola.empty()){
					int top=cola.front();
					cola.pop();
					for(int i=0;i<n;i++){
						if(!h[i]){
							h[i]=top;
							r+=(w[top]*v[i]);
							break;
						}
					}
					us++;
				}
			}			
		}
		cout <<r<<"\n";
	}
