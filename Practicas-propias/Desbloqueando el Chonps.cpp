#include <bits/stdc++.h>
using namespace std;
#define MAX 2002
int n,res;
int arr[MAX];
string w[MAX];
bool vis[MAX];
int dist[MAX][MAX];
set<pair<int,int> >cola;
int dis(string a,string b){
	int s=0;
	for(int i=0;i<a.size();i++){
		int x=a[i]-'0',y=b[i]-'0';
		s+=min(abs(x-y),abs(abs(x-y)-10));
	}
	return s;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>w[i];
		}
		w[0]="0000";
		for(int i=0;i<=n;i++){
			arr[i]=(1<<30);
			for(int j=0;j<=n;j++){
				dist[i][j]=dis(w[i],w[j]);
			}
		}
		int idx=1;
		for(int i=1;i<=n;i++){
			if(dist[0][i]<dist[0][idx])idx=i;
		}
		arr[idx]=dist[0][idx];
		cola.insert(make_pair(dist[0][idx],idx));
		while(!cola.empty()){
	    pair<int,int>padre=*cola.begin(); 
	    cola.erase(padre);
	    int pos=padre.second;
	    vis[pos]=true;
	    res+=arr[pos];
	    for(int i=1;i<=n;i++)
	       if(!vis[i]&&arr[i]>dist[pos][i]){
	           cola.erase(make_pair(arr[i],i));
	           arr[i]=dist[pos][i];
	           cola.insert(make_pair(arr[i],i));
	       }
	}
		cout <<res<<"\n";
	}
