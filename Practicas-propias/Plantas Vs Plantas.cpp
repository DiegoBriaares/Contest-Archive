#include <iostream>
using namespace std;
#define MAX 1000002
int n,p=0;
int pila[MAX];
int v[MAX];
int many[MAX];
int r=0,res;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		for(int i=n;i>0;i--){
			r=0;
			while(v[i]>pila[p]&&p>0){
				if(many[p]>r)r=many[p];
				else r++;
				p--;
			}
			pila[++p]=v[i];
			many[p]=r;
			res=max(res,r);
		}
		cout <<res<<"\n";
	}
