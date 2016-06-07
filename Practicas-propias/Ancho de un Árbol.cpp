#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
int izq[MAX],der[MAX];
int v[MAX];
int n;
int r,r2;
int l=1;
void solve(int nodo,int lvl){
	if(nodo!=-1){
		solve(izq[nodo],lvl+1);
		if(!v[lvl]){
			v[lvl]=l;
		}
		int dif=l-v[lvl]+1;
		if(dif>r2||dif==r2&&lvl<r){
			r2=dif;
			r=lvl;
		}
		l++;
		solve(der[nodo],lvl+1);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		int uso;
		for(int i=0;i<n;i++){
			cin>>uso;
			cin>>izq[uso];
			cin>>der[uso];
		}	
		l=1;
		solve(1,1);
		cout << r<<" "<<r2<"\n";
	}
