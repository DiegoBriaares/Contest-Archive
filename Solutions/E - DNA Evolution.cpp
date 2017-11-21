#include <bits/stdc++.h>
using namespace std;
#define MAX 100012
string v;
int n,q,l,r;
int solve(char c){
	if(c=='A')return 0;
	if(c=='T')return 1;
	if(c=='G')return 2;
	if(c=='C')return 3;
}
struct node {
	int tree[11][11][MAX];
	void act(int fenwick[],int i,int x){
	//	cout << "Actualize\n";
		while(i<MAX){
			fenwick[i]+=x;
			i+=(i&-i);
		}
	}
	void update(int idx,int x){
		for(int i=1;i<=10;i++){
			//cout << "Trate\n";
			act(tree[i][idx%i],idx,x);
		}
	}
	int sum(int fenwick[],int i){
		if(i==0)return 0;
		int res=0;
		while(i>0){
			res+=fenwick[i];
			i-=(i&-i);
		}
		return res;
	}
	int query(int idx,int tam){
		return sum(tree[tam][idx%tam],r)-sum(tree[tam][idx%tam],(l-1));	
	}
};
node bit[5];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>v;
		n=v.size();
		for(int i=0;i<n;i++){
			//cout << "pass1\n";
			int c=solve(v[i]);
			bit[c].update(i+1,1);
		//	cout << "pass2\n";
		}
		cin>>q;
		while(q--){
			int op;
			cin>>op;
			if(op==1){
				int x;
				char c;
				cin>>x>>c;
				bit[solve(v[x-1])].update(x,-1);
				v[x-1]=c;
				bit[solve(c)].update(x,1);
			}
			else {
				string e;
				cin>>l>>r>>e;
				int res=0;
				for(int i=0;i<e.size();i++){
					res+=(bit[solve(e[i])].query(l+i,e.size()));
				}
				cout << res<<"\n";
			}
		}
	}
