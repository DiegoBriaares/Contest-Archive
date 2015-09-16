#include <bits/stdc++.h>
using namespace std;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		long long n,c,uso,uso2=0,r,i;
		char m;
		queue<long long>fila;
		cin >>c>>n;
		for(i=1;i<=n;i++){
			cin>>m;
			if(m=='N'){
				cin>>uso;
				uso2++;
				uso++;
				fila.push(uso);
			}
			else if(m=='A'){
				uso=fila.front();
				c-=uso;
				fila.pop();
				uso2--;
			}
			else if(m=='C'){
				cout << uso2 << "\n";
			}
			else if(m=='R'){
				cout << c << "\n";
			}
		}
	}
