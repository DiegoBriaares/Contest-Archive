#include <bits/stdc++.h>
using namespace std;
#define MAX 10002
#define ll long long
ll N;
vector<double> suma,resta;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		double cT,cF,res,a,b;
		while(cin>>N){
			res=0;
			cT=N;
			cF=0;
			for(int i=0;i<N;i++){
				cin>>a>>b;
				suma.push_back(a+b);
				resta.push_back(a-b);
			}	
			sort(suma.begin(),suma.end());
			sort(resta.begin(),resta.end());
			suma.push_back(3*1e9);
			resta.push_back(3*1e9);
			int ind=0;
			while(ind<N){
				int aux=ind;
				while(suma[aux]==suma[ind])aux++;
				cF=cF+((double)(aux-ind))*((double)(aux-ind-1));
				ind=aux;
			}
			ind=0;
			while(ind<N){
				int aux=ind;
				while(resta[aux]==resta[ind])aux++;
				cF=cF+((double)(aux-ind))*((double)(aux-ind-1));
				ind=aux;
			}
			res=cF/cT;
			res=res/cT;
			cout<<setprecision(7)<<res<<"\n";
			suma.clear();
			resta.clear();
		}
	}
