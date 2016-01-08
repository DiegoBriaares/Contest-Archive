#include <bits/stdc++.h>
using namespace std;
#define MAX 10002
#define MAXN 9999
int a,b,n;
bool v[MAX];
struct solve {
	int x;
	int d;
};
int bfs(int x){
	solve in;
	in.x=x;
	in.d=0;
	queue<solve>cola;
	cola.push(in);
	while(!cola.empty()){
		solve now = cola.front();
		cola.pop();
		if(now.x==n)return now.d; 
		if(v[now.x])continue;
		v[now.x]=1;
		solve re;
		re.x=(now.x*a>MAXN?1:now.x*a);
		re.d=now.d+1;
		cola.push(re);
		if(now.x>=b){
			solve res;
			res.x=now.x/b;
			res.d=now.d+1;
			cola.push(res);
		}
	}
	return -1;
}
	int main (){
		cin>>a>>b>>n;
		cout << bfs(1);
	}
