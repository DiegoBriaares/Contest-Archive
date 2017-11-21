#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
#define MAXN 1002
int n,r;
int v[MAX];
vector<int>primos;
bool eratos[MAXN];
bool multiplos[MAXN][MAXN];
void criba(){
	for(int i=2;i<MAXN;i++){
		if(!eratos[i]){
			for(int j=i+i;j<MAXN;j+=i){
				eratos[j]=true;
			}
		}
	}
}
void get_primes(){
	for(int i=2;i<MAXN;i++){
		if(!eratos[i])primos.push_back(i);
	}
}
void get_mult(){
	for(int i=1;i<MAXN;i++){
		for(int j=1;i*j<MAXN;j++){
			multiplos[i][i*j]=true;
		}
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		criba();
		get_primes();
		get_mult();
		int mcd=v[0];
		for(int i=1;i<n;i++){  //Verifico si converge.
			mcd=__gcd(mcd,v[i]);
		}
		if(mcd>1){
			cout << "-1\n";
			return 0;
		}
		for(int i=0;i<primos.size();i++){
			int p=primos[i],ans=0,uso=0;
			if(multiplos[p][v[0]]){
				for(int j=n-1;j>=0&&multiplos[p][v[j]];j--){
					//cout << "ESPECIAL: "<<p <<" "<<v[j]<<"\n";
					uso++;
				}
			}
			for(int j=0;j<n;j++){
				if(multiplos[p][v[j]]){
					//cout << "REGULAR: "<<p<<" "<<v[j]<<" "<<uso<<"\n";
					uso++;
				}
				else {
					ans=max(ans,uso);
					uso=0;
				}
			}
			ans=max(ans,uso);
			r=max(r,ans);
		}
		cout << r<<"\n";
	}
