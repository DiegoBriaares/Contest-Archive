#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
long long v[MAX],n,k,uso[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		long long i,j,g,h,r=0;
		cin>>n>>k;
		for(i=1;i<=n;i++){
			cin>>v[i];
		}
		queue<long long>cola;
		for(int uso2=0;uso2<k;uso2++){
			cin>>g>>h;
			memset(uso,0,sizeof(uso));
			for(i=g;i<=h;i++){
				if(!uso[v[i]])cola.push(v[i]);
				uso[v[i]]++;
			}
			r=0;
			while(!cola.empty()){
				int yolo=cola.front();
				r+=((uso[yolo]*uso[yolo])*yolo);
				//cout << "R: "<<uso[yolo]<<" "<<yolo<<"\n";
				cola.pop();
			}
			cout << r<<"\n";
		}
	}
