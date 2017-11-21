#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
int N;
ll q,d,p;
ll pila[MAX],persist[MAX],v[MAX];
void apila(){
	pila[p]=d;
	int i;
	for(i=p-1;i&&d>=pila[i];i=v[i]);
	persist[p]=persist[i]+1;
	v[p]=i;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>N;
		pila[0]=(1<<30);
		while(N--){
			cin>>q;
			if(!q){   //Question
				cout << persist[p]<<"\n";
			}
			else if(q==1){
				cin>>d;
				p++,apila();
			}
			else {
				cin>>d;
				p-=d;		
			}
		}
	}
