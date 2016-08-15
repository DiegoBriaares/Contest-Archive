#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int n,k;
int pila[MAX];
int idx;
void change(){
	int i=idx,j;
	if(k>=i)j=1;
	else j=(i-k)+1;
	while(j<i){
		swap(pila[i],pila[j]);
		j++;
		i--;
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			memset(pila,0,sizeof(pila));
			idx=0;
			cin>>n>>k;
			for(int i=0;i<n;i++){
				int op,x;
				cin>>op;
				if(op==1){
					cin>>x;
					pila[++idx]=x;
				}
				else if(op==2){
					cout << pila[idx--]<<"\n";
				}
				else {
					change();
				}
			}
		}
	}
