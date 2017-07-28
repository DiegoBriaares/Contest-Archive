#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P 9001
#define MOD 10000000007
int v[10];
set<pair<ll,ll> >S;
struct node {
	string res;
	int h[8];
	int d;
};
ll hashi(int h[]){
	ll r=0;
	for(int i=0;i<8;i++){
		r*=P;
		r+=((ll)(h[i]));
		r%=MOD;
	}
	return r;
}
ll hashi2(int h[]){
	ll r=0;
	for(int i=0;i<8;i++){
		r*=P;
		r+=((ll)(h[i]));
	}
	return r;
}
void bfs(){
	queue<node>cola;
	node in;
	in.d=0;
	for(int i=0;i<8;i++){
		in.h[i]=(i+1);
	}
	cola.push(in);
	while(!cola.empty()){
		node now=cola.front();
		cola.pop();
		ll ha=hashi(now.h);
		ll ha2=hashi2(now.h);
		if(S.find(make_pair(ha,ha2))!=S.end())continue;
		S.insert(make_pair(ha,ha2));
		bool ok=false;
		for(int i=0;i<8;i++){
			if(v[i]!=now.h[i]){
				ok=true;
				break;
			}
		}
		if(!ok){
			cout << now.d<<"\n";
			for(int i=0;i<now.res.size();i++)cout << now.res[i]<<"\n";
			return;
		}
		now.d++;
		//Movimiento A.
		node x=now;
		for(int i=0,j=7;i<4;i++,j--)swap(x.h[i],x.h[j]);
		x.res+='A';
		cola.push(x);
		//Movimiento B.
		x=now;
		x.h[0]=now.h[3];
		x.h[1]=now.h[0];
		x.h[2]=now.h[1];
		x.h[3]=now.h[2];
		x.h[4]=now.h[5];
		x.h[5]=now.h[6];
		x.h[6]=now.h[7];
		x.h[7]=now.h[4];
		x.res+='B';
		cola.push(x);
		//Movimiento C.
		x=now;
		x.h[1]=now.h[6];
		x.h[2]=now.h[1];
		x.h[5]=now.h[2];
		x.h[6]=now.h[5];
		x.res+='C';
		cola.push(x);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		for(int i=0;i<8;i++){
			cin>>v[i];
		}
		bfs();
	}
