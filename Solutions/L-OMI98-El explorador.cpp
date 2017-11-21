#include <bits/stdc++.h>
using namespace std;
#define MAX 55
int m[MAX][MAX];
bool v[MAX][MAX];
int n,c,xi,yi,xf,yf;
struct solve{
	int x;
	int y;
	int d;
	solve(int x1,int y1, int d1) : x(x1),y(y1),d(d1){}
};
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int bfs(){
	solve in(xi,yi,1);
	queue<solve>Cola;
	Cola.push(in);
	while(!Cola.empty()){
		solve now = Cola.front();
		Cola.pop();
		if(now.x==xf&&now.y==yf)return now.d;
		if(v[now.x][now.y])continue;
		v[now.x][now.y]=true;
		for(int i=0;i<4;i++){
			int x=now.x+dx[i];
			int y=now.y+dy[i];
			if(x>=0&&x<n&&y>=0&&y<c&&m[x][y]!=true){
				solve r(x,y,now.d+1);
				Cola.push(r);
			}
		}
	}
	return -1;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				cin>>m[i][j];
			}
		}
		cin>>xi>>yi>>xf>>yf;
		cout << bfs()<<"\n";
	}
