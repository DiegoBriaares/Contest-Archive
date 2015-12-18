#include <bits/stdc++.h>
using namespace std;
#define MAX 402
int flag=0,n,c;
bool m[MAX];
bool m2[MAX][MAX];
struct solve {
	int h;
	int d;
	solve(int x1,int y1):h(x1),d(y1){}
};
int bfs(){
	solve in(1,0);
	queue<solve>Cola;
	Cola.push(in);
	m[1]=true;
	while(!Cola.empty()){
		solve now = Cola.front();
		Cola.pop();
		if(now.h==c)return now.d;
		for(int i=1;i<=c;i++){
			if(flag==1){
				if(!m2[now.h][i]&&!m[i]){
					m[i]=true;
					solve r(i,now.d+1);
					Cola.push(r);
				}
			}
			else {
			if(m2[now.h][i]&&!m[i]){
					m[i]=true;
					solve r(i,now.d+1);
					Cola.push(r);
				}	
			}
		}
	}
	return -1;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int i,j,g,h;
		cin>>c>>n;
		for(i=0;i<n;i++){
			cin>>g>>h;
			if(g==1&&h==c||g==c&&h==1)flag=1;
			m2[g][h]=1;
			m2[h][g]=1;
		}
			cout << bfs();
	}
