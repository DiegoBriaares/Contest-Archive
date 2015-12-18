#include <bits/stdc++.h>
using namespace std;
#define MAX 4002
bool m[MAX][MAX];
vector<int>ady[MAX];
int n,c,mini=(1<<30);
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int g,h,i,k,j;
		cin>>c>>n;
		for(i=0;i<n;i++){
			cin>>g>>h;
			m[g][h]=1;
			m[h][g]=1;
			ady[g].push_back(h);
			ady[h].push_back(g);
		}
		for(i=1;i<=c;i++){
			for(j=0;j<ady[i].size();j++){
				for(k=1;k<=c;k++){
					if(m[i][k]==1&&m[ady[i][j]][k]){
						int a=ady[i].size();
						int b=ady[ady[i][j]].size();
						int c=ady[k].size();
						mini=min(mini,(a+b+c-6));
					}
				}
			}
		}
		if(mini==(1<<30))cout <<-1;
		else cout << mini;
	}
