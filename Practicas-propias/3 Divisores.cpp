#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
bool v[MAX];
void criba(){
	for(int i=2;i<=MAX;){
		if(!v[i])for(int j=i+i;j<=MAX;j+=i){
			v[j]=true;
		}
		if(i==2)i++;
		else i+=2;
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		criba();
		v[1]=1;
		unsigned long long p,q,i,j,k=0;
		cin>>p>>q;
		for(i=sqrt(p);(i*i)<=q;i++){
			if(!v[i]&&(i*i)>=p&&(i*i)<=q&&(i&1)||i==2)k++;
		}
		cout << k<<"\n";
	}
