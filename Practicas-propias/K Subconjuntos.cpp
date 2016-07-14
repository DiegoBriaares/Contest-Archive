#include <bits/stdc++.h>
using namespace std;
#define MAX 15
vector<string>r;
bool memo[MAX];
string v,uso2;
int n,k;
void solve(int i,int many,string uso){
	if(many==k){
		r.push_back(uso);
		return;
	}
	if(i==v.size())return;
	for(int j=i;j<v.size();j++){
		if(!memo[j]){
			memo[j]=true;
			uso2=uso+v[j];
			solve(j+1,many+1,uso2);
			memo[j]=false;
		}
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		cin>>v;
		solve(0,0,"");
		sort(r.begin(),r.end());
		for(int i=0;i<r.size();i++)cout << r[i]<<"\n";
	}
