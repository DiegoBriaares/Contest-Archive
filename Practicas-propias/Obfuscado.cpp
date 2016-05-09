#include <bits/stdc++.h>
using namespace std;
#define P 407
#define ll long long
#define MOD 1000000007
string v;
string q[10002];
char x;
int n;
int cont=0;
int p=0;
bool ok;
string res;
int fin,pos;
ll hashing(string uso){
	ll r=0;
	for(int i=0;i<uso.size();i++){     
		r*=P;
		r+=(ll)(uso[i]);
		r%=MOD;
	}
	return r;
} 
int bs(int in,int fin){
	int mid;
	while(in<=fin){
		mid=(in+fin)/2;
		string uso=q[mid];
		if(x>uso[0])in=mid+1;
		else fin=mid-1;
	}
	return fin;
}
void dfs(int in,string r){
	//Si implemento alguna poda, da AC.
	if(in>fin){
		if(cont){
			cout <<"ambiguous\n";
			exit(0);
		}
		res=r;
		cont++;
		return;
	}
	string uso,k;
			x=v[in];
			int usito=in;
			for(int i=bs(1,n);i<=n;i++){
				uso=q[i];
				if(uso[0]==v[usito]&&v[usito+uso.size()-1]==uso[uso.size()-1]){
						k=v.substr(usito,uso.size());
						sort(k.begin(),k.end());
						sort(uso.begin(),uso.end());
						if(hashing(k)==hashing(uso)){
							dfs(in+q[i].size(),r+q[i]+" ");
						}
				}
			}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>v;
		cin>>n;
		fin=v.size()-1;
		for(int i=1;i<=n;i++){
			cin>>q[i];
		}	
		sort(q,q+n+1);
		dfs(0,"");
		if(!cont)cout <<"impossible\n";
		else cout <<res<<"\n";
	}
