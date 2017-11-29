#include <bits/stdc++.h>
using namespace std;
#define MAX 20002
#define ll long long
#define P 9001
#define MOD 1000000007
int n;
ll res;
string v[MAX];
map<ll,int>memo;
ll rol_hash(int in,int fin,string st){
	ll s=1;
	while(in<=fin){
		s*=P;
		s+=(st[in]);
		//s%=MOD;
		in++;
	}
	return s;
}
string sub(int in,int fin,string st){
	string sum="";
	while(in<=fin){
		sum+=st[in++];
	}
	return sum;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int ite=0;ite<n;ite++){
			set<ll>hashes;
			for(int i=0;i<v[ite].size();i++){
				for(int j=i;j<v[ite].size();j++){
					hashes.insert(rol_hash(i,j,v[ite]));
				}
			}
			for(set<ll>::iterator it=hashes.begin();it!=hashes.end();++it){
				memo[*it]++;
			}
		}
		for(int ite=0;ite<n;ite++){
			res+=((memo[rol_hash(0,v[ite].size()-1,v[ite])])-1);
		//	cout <<"AUX: "<< res<<" "<<v[ite]<<"\n";
		}
		cout << res<<"\n";
	}
